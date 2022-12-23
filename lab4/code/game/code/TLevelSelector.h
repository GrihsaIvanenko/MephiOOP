//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TLEVELSELECTIOR_H
#define LAB4_TLEVELSELECTIOR_H

#include "TMission.h"

#include <memory>
#include <iostream>


class TLevelSelector {
private:
    std::string ReadLevelNumberFromKeyboard();
    bool CheckExists(const std::string& path);
    std::string ReadLevelName();
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
            readMissionInfoFromStream(std::istream& file);
public:
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
            ChooseLevel();
};

#endif //LAB4_TLEVELSELECTIOR_H
