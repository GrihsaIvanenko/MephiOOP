//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_GAMECENTER_H
#define LAB4_GAMECENTER_H

#include "TMission.h"
#include <memory>

class TGameCenter {
private:
    std::unique_ptr<TMission> ChooseLevel();
    std::unique_ptr<TMission> Shop(std::unique_ptr<TMission> missionPtr);
    std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
public:
    void Start();
};

#endif //LAB4_GAMECENTER_H
