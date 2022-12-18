//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TSHOPPING_H
#define LAB4_TSHOPPING_H

#include "TMission.h"
#include <memory>

class TShopping {
private:
public:
    static std::unique_ptr<TMission> Shop(std::unique_ptr<TMission> missionPtr);
};

#endif //LAB4_TSHOPPING_H
