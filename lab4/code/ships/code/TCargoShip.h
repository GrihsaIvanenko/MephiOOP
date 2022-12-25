//
// Created by grigorijivanenko on 01.12.22.
//

#ifndef LAB4_TCARGOSHIP_H
#define LAB4_TCARGOSHIP_H

#include "TShip.h"

/*!
 * \brief Корабль, несущий груз. Добавляются поля - коеф замедления, максимальный груз, текущий груз.
 */


class TCargoShip : virtual public TShip {
protected:
    int WeightTotal_;
    int WeightNow_;
    /*!
     * При полной загрузке корабль имеет скорость MaxSpeed * SlowK. Замедление прямопропорционально загрузке корабля.
     */
    double SlowK_; // [0.0. 1.0) 0.0 - not matter. 1.0 - stop
public:
    TCargoShip(
            int x,
            int y,
            int ShipType,
            const std::string& ShipName,
            const TCapitanInfo& CapitanInfo,
            int MaxSpeed,
            int NowSpeed,
            int HpTotal,
            int HpNow,
            int Cost,
            int WeightTotal,
            int WeightNow,
            double SlowK);
    TCargoShip(const TCargoShip& other);
    TCargoShip& operator = (const TCargoShip& other);
    bool operator == (const TCargoShip& other) const;

    void SetWeightTotal(int weightTotal);
    void SetWeightNow(int weightNow);
    void SetSlowK(double SlowK);

    int GetWeightTotal() const;
    int GetWeightNow() const;
    double GetSlowK() const;

    /*!
     * Вычисляет скорость, с которой будет двигаться корябль, если в него загрузить weight веса
     * Вернет -1, если загружено больше максимума.
     * @param weight
     * @return
     */
    int SpeedByWeight(int weight) const; //-1 if overWeight

    /*!
     * Вычисляет максимальный вес, который можно загрузить, чтобы двигатьбся со скоростью speed
     * Вернет -1, если скорость больше максимальной.
     * @param speed
     * @return
     */
    int WeightMaxBySpeed(int speed) const; // -1 if overSpeed

    /*!
     * Определяет вывод информации в магазине об этго виде корабля.
     */
    void Print() const override;

    /*!
     * Определяет Clone для этого вида кораблей.
     * @return
     */
    std::unique_ptr<TShip> Clone() const override;
};

#endif //LAB4_TCARGOSHIP_H
