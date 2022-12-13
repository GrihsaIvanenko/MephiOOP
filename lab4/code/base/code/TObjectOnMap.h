//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TOBJECTONMAP_H
#define LAB4_TOBJECTONMAP_H

class TObjectOnMap {
private:
    int X_;
    int Y_;
public:
    TObjectOnMap(int x, int y);
    TObjectOnMap(const TObjectOnMap& other);
    virtual ~TObjectOnMap() = default;
    TObjectOnMap& operator =(const TObjectOnMap& other);
    bool operator ==(const TObjectOnMap& other) const;

    void SetX(int x);
    void SetY(int y);

    int GetX() const;
    int GetY() const;

    int DistTo(const TObjectOnMap& other) const;
};

#endif //LAB4_TOBJECTONMAP_H
