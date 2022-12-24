//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TPLAYING_H
#define LAB4_TPLAYING_H

#include "TMission.h"
#include <memory>

const int H_of_one = 1;
const int W_of_one = 1;

class TPlaying {
private:
    void FillIn(std::vector<std::vector<char>>& image, int x, int y, std::vector<std::vector<char>>& toPrint);

    void DrawPirateBase(TPirateBase* pirateBase, int x, int y, std::vector<std::vector<char>>& toPrint);
    void DrawBase(TBase* base, int x, int y, std::vector<std::vector<char>>& toPrint);
    void DrawCargoWarShip(TCargoWarShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);
    void DrawCargoShip(TCargoShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);
    void DrawWarShip(TWarShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);

    TObjectOnMap FindBest(TObjectOnMap* from, TObjectOnMap* to, int speed, const std::vector<std::vector<TObjectOnMap*>>& newPole);
    void Init(std::unique_ptr<TMission>& mission);
    void MakeSpawn(std::unique_ptr<TMission>& mission, int nowTime);
    void RefillBases(std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& newPole);
    int GetSpeed(std::unique_ptr<TShip>& ship);
    void MoveShips(MyList<std::unique_ptr<TShip>>& ships, TBase& b, std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& newPole);
    void MoveShips(MyList<TWarShip>& pirates, MyList<std::unique_ptr<TShip>>& goals, std::vector<std::vector<TObjectOnMap*>>& newPole);
    void MakeShot(MyList<std::unique_ptr<TShip>>& attack, MyList<TWarShip>& defend, int nowTime);
    void MakeShot(MyList<TWarShip>& attack, MyList<std::unique_ptr<TShip>>& defend, int nowTime);
    void RemoveRipped(MyList<std::unique_ptr<TShip>>& ships);
    void RemoveRipped(MyList<TWarShip>& ships);

    void MakeMoves(std::unique_ptr<TMission>& mission, int nowTime);
    void ShowOnScreen(std::unique_ptr<TMission>& mission);
    void FillPole(std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& pole);
    void FillPoint(TObjectOnMap* object, int line, int pos, std::vector<std::vector<char>>& toPrint);
public:
    std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
};

#endif //LAB4_TPLAYING_H
