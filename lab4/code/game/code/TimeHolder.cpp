//
// Created by grigorijivanenko on 24.12.22.
//

#include "TimeHolder.h"
#include <cmath>

void TimeHolder::Start() {
    PrevMoment_ = clock();
    ClocksFromStart_ = 0;
}

void TimeHolder::UpdateClocks() {
    clock_t now = clock();
    ClocksFromStart_ += now - PrevMoment_;
    PrevMoment_ = now;
}

int TimeHolder::GetTact() {
    UpdateClocks();
    double seconds = (double)ClocksFromStart_ / CLOCKS_PER_SEC;
    double oneSec = 1.0 / FPS;
    double kadr = seconds / oneSec;
    int numberKadr = std::floor(kadr);
    return numberKadr;
}