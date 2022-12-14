//
// Created by grigorijivanenko on 13.12.22.
//

#include "TSpawnDescriptor.h"

TSpawnDescriptor::TSpawnDescriptor(const TWarShip &toSpam, int spamCount, int loopTime, int lastSpam)
    : ToSpawn_(toSpam)
    , SpamCount_(spamCount)
    , LoopTime_(loopTime)
    , LastSpam_(lastSpam)
{
    ToSpawn_.SetShipName("Pirate");
}

TSpawnDescriptor::TSpawnDescriptor(const TSpawnDescriptor &other)
    : ToSpawn_(other.ToSpawn_)
    , SpamCount_(other.SpamCount_)
    , LoopTime_(other.LoopTime_)
    , LastSpam_(other.LastSpam_)
{
     ToSpawn_.SetShipName("Pirate");
}

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
        ans.insert(std::move(ToSpawn_), ans.begin());
        --SpamCount_;
        LastSpam_ += LoopTime_;
    }
    return ans;
}

void TSpawnDescriptor::SetXY(int x, int y) {
    ToSpawn_.SetX(x);
    ToSpawn_.SetY(y);
}
