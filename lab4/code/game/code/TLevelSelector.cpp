//
// Created by grigorijivanenko on 17.12.22.
//

#include "TLevelSelector.h"
#include "TLevelReader.h"

#include <string>
#include <iostream>
#include <fstream>

std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
        TLevelSelector::ChooseLevel() {
    std::string pathToLevel = ReadLevelName();
    std::ifstream file(pathToLevel.c_str());
    auto newMission = readMissionInfoFromStream(file);
    return std::move(newMission);
}

std::string TLevelSelector::ReadLevelName() {
    std::string levelNumber = ReadLevelNumberFromKeyboard();
    std::string levelName = "../resources/levels/level" + levelNumber + ".txt";
    if (CheckExists(levelName)) {
        return levelName;
    }
    std::string reasonToFinishGame = "File with level number " + levelNumber + " does not exist!";
    throw reasonToFinishGame;
}

std::string TLevelSelector::ReadLevelNumberFromKeyboard() {
    std::cout << "Enter level number\n";
    std::string s;
    getline(std::cin, s);
    try {
        int number = std::stoi(s);
        std::string levelNumber = std::to_string(number);
        return levelNumber;
    } catch(...) {
        std::string reasonToFinishGame = "Enter an integer - level number!";
        throw reasonToFinishGame;
    }
}

bool TLevelSelector::CheckExists(const std::string& path) {
    std::ifstream file(path.c_str());
    if (file)
        return true;
    else
        return false;
}

std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
        TLevelSelector::readMissionInfoFromStream(std::istream& file) {
    auto res = TLevelReader().ReadMissionInfoFromStream(file);
    return std::move(res);
}
