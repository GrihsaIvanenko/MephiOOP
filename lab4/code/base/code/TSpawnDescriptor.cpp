//
// Created by grigorijivanenko on 13.12.22.
//

#include "TSpawnDescriptor.h"

TSpawnDescriptor::TSpawnDescriptor(const TWarShip &toSpam, int spamCount, int loopTime, int lastSpam)
    : ToSpawn_(toSpam)
    , SpamCount_(spamCount)
    , LoopTime_(loopTime)
    , LastSpam_(lastSpam)
{ }

TSpawnDescriptor::TSpawnDescriptor(const TSpawnDescriptor &other)
    : ToSpawn_(other.ToSpawn_)
    , SpamCount_(other.SpamCount_)
    , LoopTime_(other.LoopTime_)
    , LastSpam_(other.LastSpam_)
{ }

TSpawnDescriptor& TSpawnDescriptor::operator =(const TSpawnDescriptor& other) {
    ToSpawn_ = other.ToSpawn_);
    SpamCount_ = other.SpamCount_;
    LoopTime_ = other.LoopTime_;
    LastSpam_ = other.LastSpam_;
    return *this;
}

bool TSpawnDescriptor::operator ==(const TSpawnDescriptor& other) {
    return
        ToSpawn_ == other.ToSpawn_ &&
        SpamCount_ == other.SpamCount_ &&
        LoopTime_ == other.LoopTime_ &&
        LastSpam_ == other.LastSpam_;
}

MyList<TWarShip> TSpawnDescriptor::Spawn(int time) {
    MyList<TWarShip> ans;
    while (SpamCount_ > 0 && LastSpam_ + LoopTime_ < time) {
        ans.insert(ToSpawn_);
        --SpamCount_;
        LastSpam_ += LoopTime_;
    }
    return ans;
}

class TSpawnDescriptor {
private:
    TWarShip ToSpawn_;
    int SpamCount_;
    int LoopTime_;
    int LastSpam_;
public:
    TSpawnDescriptor(const TWarShip& toSpam, int spamCount, LoopTime, LastSpam);
    TSpawnDescriptor(const TSpanDescriptor& other);
    TSpawnDescriptor& operator =(const TSpanDescriptor& other);
    bool operator ==(const TSpawnDescriptor& other);

    MyList<TWarShip> Spawn(int time);
};