//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TSPAWNDESCRIPTOR_H
#define LAB4_TSPAWNDESCRIPTOR_H

#include "../../ships/code/TWarShip.h"
#include "../../container/code/MyList.h"

class TSpawnDescriptor {
private:
    TWarShip ToSpawn_;
    int SpamCount_;
    int LoopTime_;
    int LastSpam_;
public:
    TSpawnDescriptor(const TWarShip& toSpam, int spamCount, int loopTime, int lastSpam);
    TSpawnDescriptor(const TSpanDescriptor& other);
    TSpawnDescriptor& operator =(const TSpanDescriptor& other);
    bool operator ==(const TSpawnDescriptor& other);

    MyList<TWarShip> Spawn(int time);
};

#endif //LAB4_TSPAWNDESCRIPTOR_H
