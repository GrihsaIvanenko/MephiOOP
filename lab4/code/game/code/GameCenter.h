//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_GAMECENTER_H
#define LAB4_GAMECENTER_H

#include "TMission.h"
#include <memory>

std::unique_ptr<TMission> ChooseLevel();
std::unique_ptr<TMission> Shop(std::unique_ptr<TMission> mission);
void play(std::unique_ptr<TMission>, const TimeHolder& holder);

#endif //LAB4_GAMECENTER_H
