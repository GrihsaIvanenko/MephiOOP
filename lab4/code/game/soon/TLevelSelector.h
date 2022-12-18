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
    std::unique_ptr<TMission> readMissionInfoFromStream(std::istream& file);
public:
    std::unique_ptr<TMission> ChooseLevel();
};

#endif //LAB4_TLEVELSELECTIOR_H
