//
// Created by grigorijivanenko on 17.12.22.
//

#ifndef LAB4_TLEVELSELECTIOR_H
#define LAB4_TLEVELSELECTIOR_H

#include "TMission.h"

#include <memory>
#include <iostream>

/*!
 * \brief Класс, отвечающий за выбор уровня пользователем
 */

class TLevelSelector {
private:
    /*!
     * Считает строку. Если ввести не число, произойдет ошибка
     */
    std::string ReadLevelNumberFromKeyboard();

    /*!
     * Проверит, что в /resources/levels/ существует файл с именем level + номер уровня + .txt
     */
    bool CheckExists(const std::string& path);

    /*!
     * Организовывает ввод имени файла
     * Вводит номер уровня. Конструирует путь до него. Проверяет, что он существует.
     */
    std::string ReadLevelName();

    /*!
     * Вызывает вспомогательный класс, который считает из потока уровень.
     * Вернет Миссию, список орудий и кораблей для покупки в магазине
     */
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
            readMissionInfoFromStream(std::istream& file);
public:
    /*!
     * вызывает ReadLevelName. открывает файл с этим именем. после чего запускает readMissionInfoFromStream для считывания уровня.
     * Вернет Миссию, список орудий и кораблей для покупки в магазине
     */
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
            ChooseLevel();
};

#endif //LAB4_TLEVELSELECTIOR_H
