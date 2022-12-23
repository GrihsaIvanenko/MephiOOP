//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_GAMECENTER_H
#define LAB4_GAMECENTER_H

#include "TMission.h"
#include <memory>

class TGameCenter {
private:
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>> ChooseLevel();
    std::unique_ptr<TMission> Shop(
            std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>&& data);
    std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
public:
    void Start();
};

#endif //LAB4_GAMECENTER_H
