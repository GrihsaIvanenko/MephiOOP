//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TSPAWNDESCRIPTOR_H
#define LAB4_TSPAWNDESCRIPTOR_H

#include "../../ships/code/TWarShip.h"
#include "../../container/code/MyList.h"

/*!
 * \brief Класс, описываюший спавн пиратов.
 */

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

    /*!
     * Доспавнит пиратов с момента предыдущего спавна до time.
     * Вернет список появившихся кораблей.
     * @param time
     * @return
     */
    MyList<TWarShip> Spawn(int time);

    /*!
     * Функция, выставляющая XY появления кораблей для этого спавнера
     * @param x
     * @param y
     */
    void SetXY(int x, int y);
};

#endif //LAB4_TSPAWNDESCRIPTOR_H
