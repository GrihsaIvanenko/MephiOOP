//
// Created by grigorijivanenko on 23.12.22.
//

#include "gtest/gtest.h"

#include "../../../../game/code/TShop.h"

#include <fstream>

TEST(TShop, ReadInt1) {
    std::string pathToLevel = "./game/tests/TShop/data/readInt/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    int A = TShop().ReadInt(file, 0, 3);
    ASSERT_EQ(A, 2);

}

TEST(TShop, ReadInt2) {
    std::string pathToLevel = "./game/tests/TShop/data/readInt/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        int A = TShop().ReadInt(file, 0, 2);
        ASSERT_EQ(true, false);
    } catch (const std::string& s) {
        ASSERT_EQ(s, "input number(2) is not in [0, 2)");
    }

}

TEST(TShop, ReadInt3) {
    std::string pathToLevel = "./game/tests/TShop/data/readInt/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        int A = TShop().ReadInt(file, 0, 3);
        ASSERT_EQ(true, false);
    } catch (const std::string& s) {
        ASSERT_EQ(s, "Integer positive - so must contain only digits, but(-) detected");
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int ShipId = 1;

TWeapon weaponByTag(int type) {
    if (type == 0)
        return TWeapon(0, 100, 1, 0, 20, 0, 3, 11);
    if (type == 1)
        return TWeapon(0, 1000, 1, 0, 10, 0, 1, 12);
    std::string ex = "wrong tag in weaponByTag";
    throw ex;
}

MyList<TWeapon> GetGuns(const std::vector<int>& weaponTags) {
    MyList<TWeapon> ans;
    for (auto type : weaponTags)
        ans.insert(weaponByTag(type), ans.end());
    return std::move(ans);
}

TWeaponHolder makeWeaponHolder(int type) {
    TWeapon a = weaponByTag(0);
    TWeapon b = weaponByTag(1);
    if (type == 0)
        return TWeaponHolder(nullptr, nullptr, nullptr, nullptr);
    if (type == 1)
        return TWeaponHolder(nullptr, &a, &a, &b);
    std::string ex = "wrong tag in makeWeaponHolder";
    throw ex;
}


std::unique_ptr<TShip> CargoShipByTag(int tag) {
    if (tag == 0) {
        return std::make_unique<TCargoShip>(
                0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 0, 0, 0, 0, 150, 1000, 0, 1.0);
    } else {
        std::string ex = "wrong tag in CargoShipByTag";
        throw ex;
    }
}

std::unique_ptr<TShip> WarShipByTag(int tag) {
    if (tag == 0) {
        return std::make_unique<TWarShip>(
                0, 0, 11, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 0, 0, 0, 0, 200, makeWeaponHolder(0) );
    }  else if (tag == 1) {
        return std::make_unique<TWarShip>(
                0, 0, 11, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 0, 0, 0, 0, 200, makeWeaponHolder(1));
    }
    std::string ex = "wrong tag in WarShipByTag";
    throw ex;
}

std::unique_ptr<TShip> CargoWarShipByTag(int tag) {
    if (tag == 0) {
        return std::make_unique<TCargoWarShip>(
                0, 0, 11, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 0, 0, 0, 0, 200, 1000, 0, 1.0,  makeWeaponHolder(0));
    }  else {
        std::string ex = "wrong tag in WarShipByTag";
        throw ex;
    }
}

MyList<std::unique_ptr<TShip>> GetShips(
        const std::vector<int>& cargoShipTags,
        const std::vector<int>& warShipTags,
        const std::vector<int>& cargoWarShipTags) {
    MyList<std::unique_ptr<TShip>> ans;
    for (auto type : cargoShipTags)
        ans.insert(std::move(CargoShipByTag(type)), ans.end());
    for (auto type : warShipTags)
        ans.insert(std::move(WarShipByTag(type)), ans.end());
    for (auto type : cargoWarShipTags)
        ans.insert(std::move(CargoWarShipByTag(type)), ans.end());
    return std::move(ans);
}


std::unique_ptr<TMission> MakeMission(
        const std::vector<int>& cargoShipTags,
        const std::vector<int>& warShipTags,
        const std::vector<int>& cargoWarShipTags,
        int money = 0, int weight = 0) {
    std::unique_ptr<TMission> ans = std::make_unique<TMission>(
            TCapitanInfo(), money, weight, 0, 0, 0, TBase(0, 0, 1), TBase(0, 0, 2), MyList<TPirateBase>());
    MyList<std::unique_ptr<TShip>>& convoy = ans->GetConvoy();
    for (auto type : cargoShipTags)
        convoy.insert(std::move(CargoShipByTag(type)), convoy.end());
    for (auto type : warShipTags)
        convoy.insert(std::move(WarShipByTag(type)), convoy.end());
    for (auto type : cargoWarShipTags)
        convoy.insert(std::move(CargoWarShipByTag(type)), convoy.end());
    return std::move(ans);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, AskPlay1) {
    std::string pathToLevel = "./game/tests/TShop/data/askPlay/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    bool res = TShop().AskPlay(MakeMission({}, {}, {}, 0), file);
    ASSERT_EQ(res, false);
}


TEST(TShop, AskPlay2) {
    std::string pathToLevel = "./game/tests/TShop/data/askPlay/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    bool res = TShop().AskPlay(MakeMission({}, {}, {}, 0), file);
    ASSERT_EQ(res, true);
}



TEST(TShop, AskPlay3) {
    std::string pathToLevel = "./game/tests/TShop/data/askPlay/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        bool A = TShop().AskPlay(MakeMission({}, {}, {}, 0), file);
        ASSERT_EQ(true, false);
    } catch (const std::string& s) {
        ASSERT_EQ(s, "You wrote(yes) instead Of Yes/No");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, BuyShip1) {
    std::string pathToLevel = "./game/tests/TShop/data/buyShip/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 1000);
    MyList<std::unique_ptr<TShip>> ships = GetShips({0}, {0}, {0});
    TShop().BuyShip(mission, ships, file);
    ASSERT_EQ(mission->GetConvoy().size(), 1);
}

TEST(TShop, BuyShip2) {
    std::string pathToLevel = "./game/tests/TShop/data/buyShip/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 1000);
    MyList<std::unique_ptr<TShip>> ships = GetShips({0}, {0}, {0});
    try {
        TShop().BuyShip(mission, ships, file);
        ASSERT_EQ(mission->GetConvoy().size(), 0);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(100) is not in [0, 4)");
    }
}

TEST(TShop, BuyShip3) {
    std::string pathToLevel = "./game/tests/TShop/data/buyShip/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 10);
    MyList<std::unique_ptr<TShip>> ships = GetShips({0}, {0}, {0});
    TShop().BuyShip(mission, ships, file);
    ASSERT_EQ(mission->GetConvoy().size(), 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, sellShip1) {
    std::string pathToLevel = "./game/tests/TShop/data/sellShip/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 10);
    try {
        TShop().SellShip(mission, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(0) is not in [0, 0)");
    }
}

TEST(TShop, sellShip2) {
    std::string pathToLevel = "./game/tests/TShop/data/sellShip/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {}, {}, 10);
    TShop().SellShip(mission, file);
    ASSERT_EQ(mission->GetMoney(), 10 + 150);
}

TEST(TShop, sellShip3) {
    std::string pathToLevel = "./game/tests/TShop/data/sellShip/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 10);
    TShop().SellShip(mission, file);
    ASSERT_EQ(mission->GetMoney(), 10 + 200 + 11 + 11 + 12);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, BuyGun1) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    MyList<TWeapon> guns = GetGuns({0, 1});
    TShop().BuyGun(mission, guns, file);
    ASSERT_EQ(mission->GetMoney(), 20 - 12);
}

TEST(TShop, BuyGun2) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 5);
    MyList<TWeapon> guns = GetGuns({0, 1});
    TShop().BuyGun(mission, guns, file);
    ASSERT_EQ(mission->GetMoney(), 5);
}

TEST(TShop, BuyGun3) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    MyList<TWeapon> guns = GetGuns({0, 1});
    TShop().BuyGun(mission, guns, file);
    ASSERT_EQ(mission->GetMoney(), 20 + 11 - 12);
}

TEST(TShop, BuyGun4) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    MyList<TWeapon> guns = GetGuns({0, 1});
    try {
        TShop().BuyGun(mission, guns, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(4) is not in [0, 4)");
    }
}

TEST(TShop, BuyGun5) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test5.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    MyList<TWeapon> guns = GetGuns({0, 1});
    try {
        TShop().BuyGun(mission, guns, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(2) is not in [0, 2)");
    }
}

TEST(TShop, BuyGun6) {
    std::string pathToLevel = "./game/tests/TShop/data/buyGun/test6.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    MyList<TWeapon> guns = GetGuns({0, 1});
    TShop().BuyGun(mission, guns, file);
    ASSERT_EQ(mission->GetMoney(), 20);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, sellGun1) {
    std::string pathToLevel = "./game/tests/TShop/data/sellGun/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    TShop().SellGun(mission, file);
    ASSERT_EQ(mission->GetMoney(), 20 + 11);
}

TEST(TShop, sellGun2) {
    std::string pathToLevel = "./game/tests/TShop/data/sellGun/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    TShop().SellGun(mission, file);
    ASSERT_EQ(mission->GetMoney(), 20);
}

TEST(TShop, sellGun3) {
    std::string pathToLevel = "./game/tests/TShop/data/sellGun/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    try {
        TShop().SellGun(mission, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(5) is not in [0, 4)");
    }
}

TEST(TShop, sellGun4) {
    std::string pathToLevel = "./game/tests/TShop/data/sellGun/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    TShop().SellGun(mission, file);
    ASSERT_EQ(mission->GetMoney(), 20);
}

TEST(TShop, sellGun5) {
    std::string pathToLevel = "./game/tests/TShop/data/sellGun/test5.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {}, 20);
    try {
        TShop().SellGun(mission, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(2) is not in [0, 2)");
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, addWeight1) {
    std::string pathToLevel = "./game/tests/TShop/data/addWeight/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {0}, 20, 200);
    TShop().AddWeight(mission, file);
    MyList<std::unique_ptr<TShip>>& conv = mission->GetConvoy();
    ASSERT_EQ(mission->GetWeightPutted(), 100);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(conv.getById(2).get())->GetWeightNow(), 100);
}

TEST(TShop, addWeight2) {
    std::string pathToLevel = "./game/tests/TShop/data/addWeight/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {0}, 20, 200);
    TShop().AddWeight(mission, file);
    MyList<std::unique_ptr<TShip>>& conv = mission->GetConvoy();
    ASSERT_EQ(mission->GetWeightPutted(), 100);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(conv.getById(0).get())->GetWeightNow(), 100);
}

TEST(TShop, addWeight3) {
    std::string pathToLevel = "./game/tests/TShop/data/addWeight/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {0}, 20, 100);
    try {
        TShop().AddWeight(mission, file);
        ASSERT_EQ(true, false);
    } catch(const std::string& ex) {
        ASSERT_EQ(ex, "input number(1000) is not in [0, 101)");
    }
}

TEST(TShop, addWeight4) {
    std::string pathToLevel = "./game/tests/TShop/data/addWeight/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    std::unique_ptr<TMission> mission = MakeMission({0}, {1}, {0}, 20, 200);
    TShop().AddWeight(mission, file);
    MyList<std::unique_ptr<TShip>>& conv = mission->GetConvoy();
    ASSERT_EQ(mission->GetWeightPutted(), 0);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(conv.getById(1).get()), nullptr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TShop, autoWeight1) {
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 20, 500);
    std::unique_ptr<TShip> newShip1 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 100, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip1), mission->GetConvoy().end());
    TShop().AutoWeight(mission);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(0).get())->GetWeightNow(), 500);
}

TEST(TShop, autoWeight2) {
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 20, 1000);
    std::unique_ptr<TShip> newShip1 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 100, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip1), mission->GetConvoy().end());
    std::unique_ptr<TShip> newShip2 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 60, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip2), mission->GetConvoy().end());
    TShop().AutoWeight(mission);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(0).get())->GetWeightNow(), 880);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(1).get())->GetWeightNow(), 120);
}

TEST(TShop, autoWeight3) {
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 20, 1000);

    std::unique_ptr<TShip> newShip1 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 100, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip1), mission->GetConvoy().end());
    std::unique_ptr<TShip> newShip2 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 60, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip2), mission->GetConvoy().end());
    std::unique_ptr<TShip> newShip3 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 10, 0, 0, 0, 0, 1000, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip3), mission->GetConvoy().end());

    TShop().AutoWeight(mission);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(0).get())->GetWeightNow(), 1000);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(1).get())->GetWeightNow(), 0);
    ASSERT_EQ(dynamic_cast<TCargoShip*>(mission->GetConvoy().getById(2).get())->GetWeightNow(), 0);
}

TEST(TShop, autoWeight4) {
    std::unique_ptr<TMission> mission = MakeMission({}, {}, {}, 20, 1000);
    std::unique_ptr<TShip> newShip1 = std::make_unique<TCargoShip>( 0, 0, 0, "Ship" + std::to_string(ShipId++), TCapitanInfo(), 100, 0, 0, 0, 0, 500, 0, 0.5);
    mission->GetConvoy().insert(std::move(newShip1), mission->GetConvoy().end());
    try {
        TShop().AutoWeight(mission);
        ASSERT_EQ(true, false);
    } catch(const std::string ex) {
        ASSERT_EQ(ex, "Total weight bigger than ships can contain");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
