//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TPLAYING_H
#define LAB4_TPLAYING_H

#include "../code/TMission.h"
#include <memory>

class TPlaying {
private:
public:
    static std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
};

#endif //LAB4_TPLAYING_H
