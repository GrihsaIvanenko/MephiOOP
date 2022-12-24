//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TIMEHOLDER_H
#define LAB4_TIMEHOLDER_H

#include <time.h>

class TimeHolder {
private:
    inline static clock_t PrevMoment_ = 0;
    inline static clock_t ClocksFromStart_ = 0;
    void UpdateClocks();
    const double FPS = 4;
public:
    void Start();
    virtual int GetTact();
};

#endif //LAB4_TIMEHOLDER_H
