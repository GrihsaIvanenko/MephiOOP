//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_GAMECENTER_H
#define LAB4_GAMECENTER_H

#include "TMission.h"
#include <memory>

/*!
 * \brief Класс, запускающий различные стадии игры
 */
class TGameCenter {
private:
    /*!
     * вызвает класс, реализовывающий выбор уровня и его загрузку из файла
     * Возвращает Миссию, Список орудий и коралей, которые можно купить
     */
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>> ChooseLevel();

    /*
     * вызвает класс, реализовывающий покупку орудий и кораблей
     * Принимает Миссию, Список орудий и коралей, которые можно купить
     * Возвращает миссию, в которой добавлены купленные игроком корабли и орудия
     */
    std::unique_ptr<TMission> Shop(
            std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>&& data);

    /*
     * вызвает класс, реализовывающий логику и происходящее в игре
     * Принимает дескриптор миссии после загрузки и покупуки
     * Возвращает указатель на миссию после игры
     */
    std::unique_ptr<TMission> Play(std::unique_ptr<TMission> missionPtr);
public:
    void Start();
};

#endif //LAB4_GAMECENTER_H
