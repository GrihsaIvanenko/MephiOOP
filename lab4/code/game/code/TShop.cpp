//
// Created by grigorijivanenko on 20.12.22.
//

#include "TShop.h"
#include <vector>

std::unique_ptr<TMission> TShop::Shop(
            std::pair<std::unique_ptr<TMission>,
            std::pair<MyList<TWeapon>,
            MyList<std::unique_ptr<TShip>>>>&& data,
            std::istream& file) {
    std::unique_ptr<TMission> missionAfterShop =
            MainMenu(std::move(data.first), std::move(data.second.first), std::move(data.second.second));
    return std::move(missionAfterShop);
}

std::unique_ptr<TMission> TShop::MainMenu(
            std::unique_ptr<TMission> mission,
            MyList<TWeapon>&& weapons_,
            MyList<std::unique_ptr<TShip>>&& ships_,
            std::istream& file) {
    std::vector<std::string>> options = {
      "0. Play",
      "1. Buy Ship",
      "2. Sell Ship",
      "3. Buy Gun",
      "4. Sell Gun",
      "5. Add Weight to Ship"
      "6. Remove Weight to Ship",
      "7. Auto Weight"
    };
    MyList<TWeapon> weapons = std::move(weapons_),
    MyList<std::unique_ptr<TShip>> ships = std::move(ships_),

    while (true) {
        printOptions(options);
        try {
            int option = ReadInt(file, 0, Optins.size());
            if (option == 0) {
                if(AskPlay(mission, file))
                    break;
            } else if (option == 1) {
                BuyShip(mission, ships, file);
            } else if (option == 2) {
                SellShip(mission, file);
            } else if (option == 3) {
                BuyGun(mission, guns, file);
            } else if (option == 4) {
                SellGun(mission, file);
            } else if (option == 5) {

            } else if (option == 6) {

            } else if (option == 7) {

            }
        } catch(const std::string check) {
            cout << check << '\n';
        }
        PrintInfo(mision);
    }
    return std::move(mission);
}

bool TShop::AskPlay(std::unique_ptr<TMission>& mission, std::istream& file) {
    PrintInfo(mission);
    std::cout << "You are certainly want to start?(Yes/No)\n";
    std::string ans;
    getline(file, ans);
    if (ans == "Yes")
        return true;
    if (ans == "No")
        return false;
    std::string ex = "You wrote(" + ans + ") instreadOf Yes/No";
    throw ex;
}

void TShop::PrintOptions(const std::vector<std::string>>& options) {
    std::cout << "-----------------------------\n";
    for (const auto& option : options) {
        std::cout << option << '\n';
    }
    std::cout << "-----------------------------\n";
}

void TShop::PrintInfo(std::unique_ptr<TMission>& mission) {
    for (const auto& ship : mission->GetConvoy())
        ship->Print();
    std::cout << "You have also " << mission->GetMoney() << " money\n";
}

void TShop::ByShip(std::unique_ptr<TMission>& mission, const MyList<std::unique_ptr<TShip>>& ships, std::istream& file) {
    std::cout << "Info about ships you can buy\n";
    int timer = 0;
    for (const auto& ship : ships) {
        std::cout << "Ship number" << timer << "\n";
        ship.Print();
    }
    std::cout << "You have " << mission->GetMoney() << '\n';
    std::cout << "Enter which ship you want to Buy. Enter 0 to exit";
    int ShipId = ReadInt(file, 0, ships.size() + 1);
    if (ShipId == 0) {
        return;
    }
    --ShipId;
    TShip* nw = ships.getById(ShipId).get();
    if (nw->GetCost() > mission->GetMoney()) {
        std::cout << "Not enough money to buy\n";
        return;
    }
    std::unique_ptr<TShip> newShip = nw->Clone();
    mission->SetMoney(mission->GetMoney() - nw->GetCost());
    MyList<std::unique_ptr<TShip>>& convoy = mission->GetConvoy();
    convoy.insert(std::move(newShip, convoy.begin()));
    std::cout << "Ship bought";
}

void TShop::SellShip(std::unique_ptr<TMission>& mission, std::istream& file) {
    PrintInfo(mission);
    std::cout << "Enter ShipNumber you want to sell\n";
    MyList<std::unique_ptr<TShip>>& convoy = mission->GetConvoy();
    int ShipId = ReadInt(file, 0, convoy.size());
    auto it = convoy.begin();
    for (int i = 0; i < ShipId; ++i)
        ++it;
    if (dynamic_cast<TWarShip*>((*it).get()))
        mission->SetMoney(mission->GetMoney() + dynamic_cast<TWarShip*>((*it).get())->GetCostWithGuns());
    else
        mission->SetMoney(mission->GetMoney() + (*it)->GetCost());
    convoy.erase(it);
}

void TShop::BuyGun(std::unique_ptr <TMission> &mission, const MyList<TWeapon> &guns, std::istream &file) {
    PrintInfo(mission);

    std::cout << "Enter ShipNumber where be new Gun\n";
    MyList<std::unique_ptr<TShip>>& convoy = mission->GetConvoy();
    int ShipId = ReadInt(file, 0, convoy.size());
    for (int i = 0; i < ShipId; ++i)
        ++it;
    if (!dynamic_cast<TWarShip*>((*it).get())) {
        std::cout << "You cant set gun at this ship\n";
        return;
    }
    TWarShip* ship = dynamic_cast<TWarShip*>((*it).get());

    int timer = 0;
    for (const auto& gun : guns) {
        std::cout << "Gun number " << timer << '\n';
        ++timer;
        gun.Print();
    }
    std::cout << "Enter GunNumber you want to buy\n";
    int GunId = ReadInt(file, 0, guns.size());
    TWeapon gun = guns.getById(GunId);
    if (mission->GetMoney() < gun.GetCost()) {
        std::cout << "Not enough money to buy\n";
        return;
    }
    mission->SetMoney(mission->GetMoney() - gun.GetCost());

    std::cout << "Where new gun will be? If place not free, previus gun will be sold\n";
    std::cout << "0. ShipFront\n";
    std::cout << "1. ShipBack\n";
    std::cout << "2. ShipLeftSide\n";
    std::cout << "3. ShipRightSize\n";
    int placeId = ReadInt(file, 0, 4);

    auto& holder = ship->GetHolder();

    int sellMoney = 0;
    if (placeId == 0) {
        if (holder.GetGunByPlace(ShipFront))
            sellMoney += holder.GetGunByPlace(ShipFront).GetCost();
        holder.SetGunByPlace(ShipFront, gun);
    }
    if (placeId == 1) {
        if (holder.GetGunByPlace(ShipBack))
            sellMoney += holder.GetGunByPlace(ShipBack).GetCost();
        holder.SetGunByPlace(ShipBack, gun);
    }
    if (placeId == 2) {
        if (holder.GetGunByPlace(ShipLeftSide))
            sellMoney += holder.GetGunByPlace(ShipLeftSide).GetCost();
        holder.SetGunByPlace(ShipLeftSide, gun);
    }
    if (placeId == 3) {
        if (holder.GetGunByPlace(ShipRightSide))
            sellMoney += holder.GetGunByPlace(ShipRightSide).GetCost();
        holder.SetGunByPlace(ShipRightSide, gun);
    }
    mission->SetMoney(mission->GetMoney() + sellMoney);
    std::cout << "Gun is bought!\n";
}

void TShop::SellGun(std::unique_ptr <TMission> &mission, std::istream &file) {
    PrintInfo(mission);

    std::cout << "Enter ShipNumber where be gun be sold\n";
    MyList<std::unique_ptr<TShip>>& convoy = mission->GetConvoy();
    int ShipId = ReadInt(file, 0, convoy.size());
    for (int i = 0; i < ShipId; ++i)
        ++it;
    if (!dynamic_cast<TWarShip*>((*it).get())) {
        std::cout << "This ship cant contain gun\n";
        return;
    }
    TWarShip* ship = dynamic_cast<TWarShip*>((*it).get());
    std::cout << "Where new gun will be sold? If place not free, nothing happen\n";
    std::cout << "0. ShipFront\n";
    std::cout << "1. ShipBack\n";
    std::cout << "2. ShipLeftSide\n";
    std::cout << "3. ShipRightSize\n";
    int placeId = ReadInt(file, 0, 4);

    auto& holder = ship->GetHolder();

    int addMoney = 0;
    if (placeId == 0) {
        if (holder.GetGunByPlace(ShipFront)) {
            addMoney += holder.GetGunByPlace(ShipFront)->GetCost();
            std::cout << "Sold!\n";
            holder.SetGunByPlace(ShipFront, nullptr);
        } else {
            std::cout << "No gun here\n";
        }
    }
    if (placeId == 1) {
        if (holder.GetGunByPlace(ShipBack)) {
            addMoney += holder.GetGunByPlace(ShipBack)->GetCost();
            std::cout << "Sold!\n";
            holder.SetGunByPlace(ShipBack, nullptr);
        } else {
            std::cout << "No gun here\n";
        }
    }
    if (placeId == 2) {
        if (holder.GetGunByPlace(ShipLeftSide)) {
            addMoney += holder.GetGunByPlace(ShipLeftSide)->GetCost();
            std::cout << "Sold!\n";
            holder.SetGunByPlace(ShipLeftSide, nullptr);
        } else {
            std::cout << "No gun here\n";
        }
    }
    if (placeId == 3) {
        if (holder.GetGunByPlace(ShipRightSide)) {
            addMoney += holder.GetGunByPlace(ShipRightSide)->GetCost();
            std::cout << "Sold!\n";
            holder.SetGunByPlace(ShipRightSide, nullptr);
        } else {
            std::cout << "No gun here\n";
        }
    }
    mission->SetMoney(mission->GetMoney() + addMoney);
}

int TShop::ReadInt(std::stream& file, int from, int to) { // [, )
	std::string line;
    getline(file, line);
	for (auto x : line)
        if (!('0' <= x && x <= '9')) {
            std::string tmp;
            tmp.push_back(x);
            std::string errorReading = "Integer positive - so must contain only digits, but(" + tmp + ") detected";
            throw errorReading;
        }
    try {
        int result = std::stoi(mainPart);
        if (result < from || result >= to) {
            std::string errorReading = "input number(" +  std::to_string(result) + ") is not in ["
                    + to_string(from) + ", " + std::to_string(to) + ")";
            throw errorReading;
        }
        return result;
    } catch(...) {
        std::string errorReading = what + " - is not integer(" + mainPart + ")";
        throw errorReading;
    }
}
