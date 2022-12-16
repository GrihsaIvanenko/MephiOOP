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
    TSpawnDescriptor(const TSpawnDescriptor& other);
    TSpawnDescriptor& operator =(const TSpawnDescriptor& other);
    bool operator ==(const TSpawnDescriptor& other) const;

    MyList<TWarShip> Spawn(int time);
};

#endif //LAB4_TSPAWNDESCRIPTOR_H
