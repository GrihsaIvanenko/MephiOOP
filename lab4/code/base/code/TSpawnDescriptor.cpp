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
    ToSpawn_ = other.ToSpawn_;
    SpamCount_ = other.SpamCount_;
    LoopTime_ = other.LoopTime_;
    LastSpam_ = other.LastSpam_;
    return *this;
}

bool TSpawnDescriptor::operator ==(const TSpawnDescriptor& other) const {
    return
        ToSpawn_ == other.ToSpawn_ &&
        SpamCount_ == other.SpamCount_ &&
        LoopTime_ == other.LoopTime_ &&
        LastSpam_ == other.LastSpam_;
}

MyList<TWarShip> TSpawnDescriptor::Spawn(int time) {
    MyList<TWarShip> ans;
    while (SpamCount_ > 0 && LastSpam_ + LoopTime_ <= time) {
        ans.insert(ToSpawn_, ans.begin());
        --SpamCount_;
        LastSpam_ += LoopTime_;
    }
    return ans;
}
