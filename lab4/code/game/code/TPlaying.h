//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TPLAYING_H
#define LAB4_TPLAYING_H

#include "TMission.h"
#include <memory>

const int H_of_one = 1;
const int W_of_one = 1;

/*!
 * \brief Класс, реализовывающий логику происходящего в игре
 */

class TPlaying {
private:
    /*!
     * Заполнит игровое поле  toPrint клеткой с корординатами (x, y), на которой изображено image
     * Закрасится прямоугольник в toPrint с координатами (x,y) (x + image.size(), y + image[0].size())
     * @param image
     * @param x
     * @param y
     * @param toPrint
     */
    void FillIn(std::vector<std::vector<char>>& image, int x, int y, std::vector<std::vector<char>>& toPrint);


    /*!
     * Рисует базу pirateBase пиратов на поле toPrint в клетке (x, y)
     * @param pirateBase
     * @param x
     * @param y
     * @param toPrint
     */
    void DrawPirateBase(TPirateBase* pirateBase, int x, int y, std::vector<std::vector<char>>& toPrint);

    /*!
     * Рисует базу base на поле toPrint в клетке (x, y)
     * @param base
     * @param x
     * @param y
     * @param toPrint
     */
    void DrawBase(TBase* base, int x, int y, std::vector<std::vector<char>>& toPrint);

    /*!
     * Рисует корабль с вооружением ship на поле toPrint в клетке (x, y)
     * @param ship
     * @param x
     * @param y
     * @param toPrint
     */
    void DrawCargoWarShip(TCargoWarShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);

    /*!
    * Рисует грузовой корабль ship на поле toPrint в клетке (x, y)
    * @param ship
    * @param x
    * @param y
    * @param toPrint
    */
    void DrawCargoShip(TCargoShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);

    /*!
    * Рисует грузовой корабль с вооружением ship на поле toPrint в клетке (x, y)
    * @param ship
    * @param x
    * @param y
    * @param toPrint
    */
    void DrawWarShip(TWarShip* ship, int x, int y, std::vector<std::vector<char>>& toPrint);

    /*!
     * Ищет ближайшую незанятую клетку  для объекта from, если он направляется в клетку to
     * Выбор клеток происходит из круга с центром в from и радиусом speed
     * @param from
     * @param to
     * @param speed
     * @param newPole
     * @return
     */
    TObjectOnMap FindBest(TObjectOnMap* from, TObjectOnMap* to, int speed, const std::vector<std::vector<TObjectOnMap*>>& newPole);

    /*!
     * Проставит всем купленным кораблям координату базы А.
     * Всем пиратским базам - выставит из создаваемых ими кораблях координаты базы, которая их порождает
     * @param mission
     */
    void Init(std::unique_ptr<TMission>& mission);

    /*!
     * Спавнит всех пиратов, которые должны появиться к моменту nowTime.
     * @param mission
     * @param nowTime
     */
    void MakeSpawn(std::unique_ptr<TMission>& mission, int nowTime);

    /*!
    * Отрисует все базы в новом кадре.
     * Займет для них места, чтобы на них не сдвинулся корабль
    * @param mission
    * @param nowTime
    */
    void RefillBases(std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& newPole);

    /*!
     * Вычислит скорость конвоя - минимальная из скоростей каждого корабля
     * @param ship
     * @return
     */
    int GetSpeed(std::unique_ptr<TShip>& ship);

    /*!
     * Сдвинет все мирные корабли на 1 ход
     * Для каждого найдет ближайщую к цели незанятую клетку, до которой он может обраться за 1 такт
     */
    void MoveShips(MyList<std::unique_ptr<TShip>>& ships, TBase& b, std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& newPole);

    /*!
     * Сдвинет все пиратские корабли на 1 ход
     * Для каждого найдет ближайщую к цели незанятую клетку, до которой он может обраться за 1 такт
     */
    void MoveShips(MyList<TWarShip>& pirates, MyList<std::unique_ptr<TShip>>& goals, std::vector<std::vector<TObjectOnMap*>>& newPole);

    /*!
     * Мирные корабли сделают залп по пиратам.
     * Каждый мирный корабль стреляет в ближайшего к нему пирата
     */
    void MakeShot(MyList<std::unique_ptr<TShip>>& attack, MyList<TWarShip>& defend, int nowTime);

    /*!
     * Пираты сделают залп по мирным кораблям.
     * Каждый Пират стреляет в ближайший к нему мирный корабль
     */
    void MakeShot(MyList<TWarShip>& attack, MyList<std::unique_ptr<TShip>>& defend, int nowTime);

    /*!
    * удалит убитые мирные корабли из общего списка
    */
    void RemoveRipped(MyList<std::unique_ptr<TShip>>& ships);

    /*!
    * удалит убитые пиратские корабли из обшего списка
    */
    void RemoveRipped(MyList<TWarShip>& ships);


    /*!
    * Отвечает за все перемещения в рамках одного хода
    */
    void MakeMoves(std::unique_ptr<TMission>& mission, int nowTime);

    /*!
    * Отвечает за отрисовку актуального состояния игры
    */
    void ShowOnScreen(std::unique_ptr<TMission>& mission);

    /*!
     * Расположит все объекты на карте в соответствии их координатам.
     * Если на одной клетке есть корабли и базы, рисуются базы.
     * Если есть обычные корабли  и пираты, рисуются пираты.
     * Среди пиратов и среди мирных кораблей нарисуется случайный(первый рассмотренный для этой клетки)
     * @param mission
     * @param pole
     */
    void FillPole(std::unique_ptr<TMission>& mission, std::vector<std::vector<TObjectOnMap*>>& pole);

    /*!
     * Отрисует объект на конкретной клетке.
     * Поймет, какой именно тип этого объекта и вызовет  соответствующий ему отрисовщик
     * @param object
     * @param line
     * @param pos
     * @param toPrint
     */
    void FillPoint(TObjectOnMap* object, int line, int pos, std::vector<std::vector<char>>& toPrint);
public:
    /*!
     * Запускает игровой процесс
     * Инит
     * Цикл игры, пересчитывающий и перерисовывающий происходящее при смене кадра(timeHolder)
     * @param missionPtr
     * @return
     */
    std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
};

#endif //LAB4_TPLAYING_H
