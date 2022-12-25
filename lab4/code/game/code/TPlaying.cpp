//
// Created by grigorijivanenko on 24.12.22.
//

#include "TPlaying.h"
#include "TimeHolder.h"
#include <iostream>
#include <algorithm>

std::unique_ptr<TMission> TPlaying::Play(std::unique_ptr <TMission> missionPtr) {
    Init(missionPtr);
    TimeHolder().Start();
    int prevKadr = TimeHolder().GetTact();
    try {
        while (true) {
            int nowKadr = TimeHolder().GetTact();
            if (prevKadr != nowKadr) {
                prevKadr = nowKadr;
                MakeMoves(missionPtr, nowKadr);
                ShowOnScreen(missionPtr);
                std::cout << nowKadr << std::endl;
            }
        }
    } catch(const std::string ex) {
        if (ex != "Win")
            throw ex;
    }
    return std::move(missionPtr);
}

void TPlaying::Init(std::unique_ptr <TMission> &mission) {
    for(auto& ship : mission->GetConvoy()) {
        ship->SetX(mission->GetBaseA().GetX());
        ship->SetY(mission->GetBaseA().GetY());
    }
    for (auto& pirateBase : mission->GetPirateBases()) {
        pirateBase.SetXYInSpawn();
    }
}

void TPlaying::MakeMoves(std::unique_ptr <TMission> &mission, int nowTime) {
    MakeSpawn(mission, nowTime);

    std::vector<std::vector<TObjectOnMap*>> newPole(
            mission->GetHeight(),
            std::vector<TObjectOnMap*>(mission->GetWidth(), nullptr));
    RefillBases(mission, newPole);

    if (mission->GetConvoy().size() == 0) {
        std::string res;
        if (mission->GetWeightCompleted() >= mission->GetWeightNeedToPass()) {
            res = "Win";
            throw res;
        }
        res =
                res +
                "Ships killed! You transfer " +
                std::to_string(mission->GetWeightCompleted()) +
                " kg of " +
                std::to_string(mission->GetWeightNeedToPass());
        throw res;
    }

    MoveShips(mission->GetConvoy(), mission->GetBaseB(), mission, newPole);
    MoveShips(mission->GetPirates(), mission->GetConvoy(), newPole);
    MakeShot(mission->GetConvoy(), mission->GetPirates(), nowTime);
    MakeShot(mission->GetPirates(), mission->GetConvoy(), nowTime);
    RemoveRipped(mission->GetConvoy());
    RemoveRipped(mission->GetPirates());
}

int TPlaying::GetSpeed(std::unique_ptr<TShip>& ship) {
    TCargoShip* cargoShip = dynamic_cast<TCargoShip*>(ship.get());
    if (cargoShip)
        return cargoShip->SpeedByWeight(cargoShip->GetWeightNow());
    else
        return ship->GetMaxSpeed();
}

TObjectOnMap TPlaying::FindBest(TObjectOnMap* from, TObjectOnMap* to, int speed, const std::vector <std::vector<TObjectOnMap *>> &newPole) {
    int Xmin = std::max(0, from->GetX() - speed);
    int Xmax = std::min((int)newPole.size(), from->GetX() + speed + 1) - 1;
    int Ymin = std::max(0, from->GetY() - speed);
    int Ymax = std::min((int)newPole[0].size(), from->GetY() + speed + 1) - 1;

    std::vector<TObjectOnMap> ables;
    for (int x = Xmin; x <= Xmax; ++x)
        for (int y = Ymin; y <= Ymax; ++y)
            if (from->DistTo(TObjectOnMap(x, y)) <= speed * speed)
            if (!newPole[x][y])
                ables.emplace_back(x, y);

    std::sort(ables.begin(), ables.end(), [&to](const TObjectOnMap& lhs, const TObjectOnMap& rhs)
    {
        return lhs.DistTo(*to) < rhs.DistTo(*to);
    });
    if (ables.size() == 0) {
        std::string ex = "No possible moves!";
        throw ex;
    }
    return ables[0];
}

void TPlaying::MoveShips(MyList<std::unique_ptr<TShip>>& ships, TBase& b, std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& newPole) {
    if (ships.size() == 0)
        return;
    int speedOfCaravan = GetSpeed(ships.getById(0));
    for (auto& shipPtr : ships) {
        speedOfCaravan = std::min(speedOfCaravan, GetSpeed(shipPtr));
    }
    for (auto& shipPtr : ships) {
        TObjectOnMap to = FindBest(shipPtr.get(), &b, speedOfCaravan, newPole);
        if (to.DistTo(b) == 1) {
            TCargoShip* cast = dynamic_cast<TCargoShip*>(shipPtr.get());
            if (cast)
                mission->SetWeightCompleted(mission->GetWeightCompleted() + cast->GetWeightNow());
            shipPtr->SetHPNow(0);
        } else {
            newPole[to.GetX()][to.GetY()] = shipPtr.get();
            shipPtr->SetX(to.GetX());
            shipPtr->SetY(to.GetY());
        }
    }
}

void TPlaying::MoveShips(MyList<TWarShip>& pirates, MyList<std::unique_ptr<TShip>>& goals, std::vector<std::vector<TObjectOnMap*>>& newPole) {
    if (goals.size() == 0)
        return;
    for (auto& pirate : pirates) {

        std::unique_ptr<TShip>* goal = &(goals.getById(0));
        for (auto& defendOne : goals)
            if (pirate.DistTo(*(defendOne.get())) < pirate.DistTo(*(goal->get())))
                goal = &defendOne;

        TObjectOnMap to = FindBest(&pirate, goal->get(), pirate.GetMaxSpeed(), newPole);
        newPole[to.GetX()][to.GetY()] = &pirate;
        pirate.SetX(to.GetX());
        pirate.SetY(to.GetY());
    }
}


void TPlaying::MakeShot(MyList<std::unique_ptr<TShip>>& attack, MyList<TWarShip>& defend, int nowTime) {
    if (!defend.size())
        return;
    for (auto& attackOne : attack) {
        if (!dynamic_cast<TWarShip*>(attackOne.get()))
            continue;
        TWarShip* goal = &(defend.getById(0));
        for (auto& defendOne : defend)
            if (attackOne->DistTo(defendOne) < attackOne->DistTo(*goal))
                goal = &defendOne;

        dynamic_cast<TWarShip*>(attackOne.get())->MakeShot(*goal, nowTime);
    }
}

void TPlaying::MakeShot(MyList<TWarShip>& attack, MyList<std::unique_ptr<TShip>>& defend, int nowTime) {
    if (!defend.size())
        return;
    for (auto& attackOne : attack) {
        std::unique_ptr<TShip>* goal = &(defend.getById(0));
        for (auto& defendOne : defend)
            if (attackOne.DistTo(*(defendOne.get())) < attackOne.DistTo(*(goal->get())))
                goal = &defendOne;
        attackOne.MakeShot(*(goal->get()), nowTime);
    }
}

void TPlaying::RemoveRipped(MyList<std::unique_ptr<TShip>>& ships) {
    auto it = ships.begin();
    while (it != ships.end()) {
        if ((*it)->GetHPNow() == 0) {
            ships.erase(it);
        } else {
            ++it;
        }
    }
}

void TPlaying::RemoveRipped(MyList<TWarShip>& ships) {
    auto it = ships.begin();
    while (it != ships.end()) {
        if ((*it).GetHPNow() == 0) {
            ships.erase(it);
        } else {
            ++it;
        }
    }
}

void TPlaying::RefillBases(std::unique_ptr <TMission> &mission, std::vector<std::vector<TObjectOnMap*>>& newPole) {
    newPole[mission->GetBaseA().GetX()][mission->GetBaseA().GetY()] = &(mission->GetBaseA());
    newPole[mission->GetBaseB().GetX()][mission->GetBaseB().GetY()] = &(mission->GetBaseB());
    for (auto& pirateBase : mission->GetPirateBases()) {
        if (!newPole[pirateBase.GetX()][pirateBase.GetY()])
            newPole[pirateBase.GetX()][pirateBase.GetY()] = &pirateBase;
    }
}

void TPlaying::MakeSpawn(std::unique_ptr <TMission> &mission, int nowTime) {
    for (auto& pirateBase : mission->GetPirateBases()) {
        MyList<TWarShip> spawned = pirateBase.GetSpawnDescriptor().Spawn(nowTime);
        for (auto& newPirateShip : spawned)
            mission->GetPirates().insert(std::move(newPirateShip), mission->GetPirates().end());
    }
}

void TPlaying::ShowOnScreen(std::unique_ptr <TMission> &mission) {
    std::vector<std::vector<TObjectOnMap*>> pole(
            mission->GetHeight(),
            std::vector<TObjectOnMap*>(mission->GetWidth(), nullptr));
    FillPole(mission, pole);

    std::vector<std::vector<char>> toPrint(mission->GetHeight() * H_of_one, std::vector<char>(mission->GetWidth() * W_of_one, '.'));
    for (int i = 0; i < mission->GetHeight(); ++i)
        for (int j = 0; j < mission->GetWidth(); ++j)
            FillPoint(pole[i][j], i * H_of_one, j * W_of_one, toPrint);


    system("clear");

    for (const auto& linePrint : toPrint) {
        for (const auto& elemPrint : linePrint)
            std::cout << elemPrint;
        std::cout << '\n';
    }
    std::cout << mission->GetWeightCompleted() << "/" << mission->GetWeightNeedToPass() << '\n';
}

void TPlaying::FillPoint(TObjectOnMap *object, int line, int pos, std::vector <std::vector<char>> &toPrint) {
    if (!object)
        return;
    if (dynamic_cast<TBase*>(object)) {
        if (dynamic_cast<TPirateBase*>(object))
            DrawPirateBase(dynamic_cast<TPirateBase*>(object), line, pos, toPrint);
        else
            DrawBase(dynamic_cast<TBase*>(object), line, pos, toPrint);
    } else if (dynamic_cast<TShip*>(object)) {
        if (dynamic_cast<TCargoShip*>(object)) {
            if (dynamic_cast<TCargoWarShip*>(object))
                DrawCargoWarShip(dynamic_cast<TCargoWarShip*>(object), line, pos, toPrint);
            else
                DrawCargoShip(dynamic_cast<TCargoShip*>(object), line, pos, toPrint);
        } else {
            DrawWarShip(dynamic_cast<TWarShip*>(object), line, pos, toPrint);
        }
    } else {
        std::string ex = "unknown object!";
        throw ex;
    }
}

void TPlaying::FillPole(std::unique_ptr <TMission> &mission, std::vector <std::vector<TObjectOnMap *>> &pole) {
    pole[mission->GetBaseA().GetX()][mission->GetBaseA().GetY()] = &(mission->GetBaseA());
    pole[mission->GetBaseB().GetX()][mission->GetBaseB().GetY()] = &(mission->GetBaseB());
    for (auto& pirateBase : mission->GetPirateBases()) {
        if (!pole[pirateBase.GetX()][pirateBase.GetY()])
            pole[pirateBase.GetX()][pirateBase.GetY()] = &pirateBase;
    }
    for (auto& ship : mission->GetConvoy())
        if (!pole[ship->GetX()][ship->GetY()])
            pole[ship->GetX()][ship->GetY()] = ship.get();
    for (auto& ship : mission->GetPirates())
        if (!pole[ship.GetX()][ship.GetY()])
            pole[ship.GetX()][ship.GetY()] = &ship;
}

void TPlaying::FillIn(std::vector <std::vector<char>> &image, int x, int y, std::vector <std::vector<char>> &toPrint) {
    for (int i = 0; i < H_of_one; ++i)
        for (int j = 0; j < W_of_one; ++j)
            toPrint[x + i][y + j] = image[i][j];
}

void TPlaying::DrawPirateBase(TPirateBase *pirateBase, int x, int y, std::vector <std::vector<char>> &toPrint) {
    std::vector<std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'P'));
    FillIn(image, x, y, toPrint);
}

void TPlaying::DrawBase(TBase *base, int x, int y, std::vector <std::vector<char>> &toPrint) {
    if (base->GetBaseType() == 1) {
        std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'A'));
        FillIn(image, x, y, toPrint);
    } else if (base->GetBaseType() == 2) {
        std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'B'));
        FillIn(image, x, y, toPrint);
    } else {
        std::string ex = "Wrong type in DrawBase";
        throw ex;
    }
}

void TPlaying::DrawCargoWarShip(TCargoWarShip *ship, int x, int y, std::vector <std::vector<char>> &toPrint) {
    std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'Z'));
    FillIn(image, x, y, toPrint);
}

void TPlaying::DrawWarShip(TWarShip *ship, int x, int y, std::vector <std::vector<char>> &toPrint) {
    if (ship->GetShipName() == "Pirate") {
        std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'J'));
        FillIn(image, x, y, toPrint);
    } else {
        std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'W'));
        FillIn(image, x, y, toPrint);
    }
}

void TPlaying::DrawCargoShip(TCargoShip *ship, int x, int y, std::vector <std::vector<char>> &toPrint) {
    std::vector <std::vector<char>> image(H_of_one, std::vector<char>(W_of_one, 'C'));
    FillIn(image, x, y, toPrint);
}
