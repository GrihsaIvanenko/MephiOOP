//
// Created by grigorijivanenko on 24.12.22.
//

#include "TPlaying.h"
#include <iostream>

std::unique_ptr<TMission> TPlaying::Play(std::unique_ptr <TMission> missionPtr) {
    std::cout << "LOX!";
    return std::move(missionPtr);
}