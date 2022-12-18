//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TIMEHOLDER_H
#define LAB4_TIMEHOLDER_H

class TimeHolder {
private:
    static int PrevTime_;
    static bool TimerGoes_;
public:
    void GetTime();
};

#endif //LAB4_TIMEHOLDER_H
