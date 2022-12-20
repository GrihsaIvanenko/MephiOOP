//
// Created by grigorijivanenko on 17.12.22.
//

#include "TGameCenter.h"

#include "TLevelSelector.h"
#include "TShopping.h"
#include "TPlaying.h"

#include <iostream>

void TGameCenter::Start() {
    try {
        auto resOfInit = ChooseLevel();
        auto missionAfterShop = Shop(std::move(it));
        auto missionAfterGame = Play(std::move(missionAfterShop));

        std::cout << "game end because of (" << "Level Completed!" << ")\n";
        std::cout << "restart game to play again!\n";
    } catch (const std::string& ex) {
        std::cout << "game end because of (" << ex << ")\n";
        std::cout << "restart game to play again!\n";
    } catch (...) {
        std::cout << "game end because of (" << "something went wrong" << ")\n";
        std::cout << "restart game to play again!\n";
    }
}

std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
            TGameCenter::ChooseLevel() {
    return std::move(TLevelSelector().ChooseLevel());
}

std::unique_ptr<TMission> Shop(
            std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>&& data) {
    return std::move(TShop().Shop(std::move(missionPtr)));
}

std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr) {
    return std::move(TPlaying().Play(std::move(missionPtr)));
}*/


