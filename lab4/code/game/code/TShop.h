//
// Created by grigorijivanenko on 20.12.22.
//

#ifndef LAB4_TSHOP_H
#define LAB4_TSHOP_H

#include "TMission.h"

class TShop {
public:
    /*!
     * Считает число из заданного диапазона [from, to)
     * @param file
     * @param from
     * @param to
     * @return
     */
    int ReadInt(std::istream& file, int from, int to);

    /*!
     * Выведет опции на экран, по одной в строке
     * @param options
     */
    void PrintOptions(const std::vector<std::string>& options);

    /*!
     * Выведет информацию о купленных кораблях и оставшихся деньгах
     * Выводится информация о каждом корабле(и об орудиях на них)
     * Затем выводится текущее количество денег
     * @param mission
     */
    void PrintInfo(const std::unique_ptr<TMission>& mission);

    /*!
     * Защита от мисклика.
     * Еще раз выведет информацию о текущих покупках.  Чтобы приступить к игре надо будет ввести Yes
     * @param mission
     * @param file
     * @return
     */
    bool AskPlay(const std::unique_ptr<TMission>& mission, std::istream& file);

    /*!
     * Купить корабль.
     * Выведут список возможных, после чего надо будет выбрать
     * Если денег хватает, корабль будет куплен.
     * @param mission
     */
    void BuyShip(std::unique_ptr<TMission>& mission, const MyList<std::unique_ptr<TShip>>& ships, std::istream& file);

    /*!
     * Продаль корабль.
     * Если на корабле есть орудия, они будут проданы, деньги от их продажи вернутся на счет
     * @param mission
     * @param file
     */
    void SellShip(std::unique_ptr<TMission>& mission, std::istream& file);

    /*!
     * Купить орудие.
     * Выведут корабли, нужно указать тот, который может нести на борту оружие.
     * Выведут варианты орудий, нужно выбрать
     * Если денег хватит - орудие будет установлено на выбранное место.
     * Если там уже было орудие - оно будет продано, а деньги вернутся на счет
     * @param mission
     * @param guns
     * @param file
     */
    void BuyGun(std::unique_ptr<TMission>& mission, const MyList<TWeapon>& guns, std::istream& file);

    /*!
     * Продать орудие.
     * Надо выбрать корабль, затем орудие.
     * При некорректном вводе выведется сообщение об ошибке, ничего не будет изменено
     * При корректном вводе - деньги вернутся на счет
     * @param mission
     * @param file
     */
    void SellGun(std::unique_ptr<TMission>& mission, std::istream& file);

    /*!
     * Разместить груз на корабль. Он должен уметь держать груз на борту. Вес не должен превосходить кол-во свободного места на корабле.
     * При некорректном вводе ничего не изменится, и будет выведено сообщение об ошибке
     * @param mission
     * @param file
     */
    void AddWeight(std::unique_ptr<TMission>& mission, std::istream& file);

    /*!
     * Снять груз с корабля. Он должен уметь держать груз на борту. Вес не должен превосходить кол-во груза места на корабле.
     * При некорректном вводе ничего не изменится, и будет выведено сообщение об ошибке
     * @param mission
     * @param file
     */
    void RemoveWeight(std::unique_ptr<TMission>& mission, std::istream& file);

    /*!
     * Автоматически расположить вес на грузовых кораблях.
     * Если вес больше суммарной вместимости грузовых кораблей - будет выведено сообщение об ошибке.
     * Если данные верны, вес будет расположен так, чтобы скорость каравана была максимально возможной.
     * @param mission
     */
    void AutoWeight(std::unique_ptr<TMission>& mission);

    /*!
     * Вспомогательная для  AutoWeight функция. Которая выставляет на каждом корабле такой вес,ъ
     * чтобы после его установи скорость была >= speed
     * @param mission
     * @param speed
     */
    void SetWeightBySpeed(std::unique_ptr<TMission>& mission, int speed);

    /*!
     * Вспомогательная для  AutoWeight функция. Которая проверяет, уместится ли груз, если каждый корабль нагружать
     * так, чтобы после загрузки он все еще мог двигаться со скоростью >= speedToCheck
     * Если есть корабль, чья максимальная скорость < speedToCheck, вернется false
     * @param mission
     * @param speedToCheck
     * @return
     */
    bool IsSpeedPossible(std::unique_ptr<TMission>& mission, int speedToCheck);

    /*!
     * диалог с пользователем, вызывающий функции, для купли/продажи чего-либо.
     * Принимает миссию после загрузки из файла, список доступных для покуки орудий и кораблей
     * Возврашает миссию после всех покупок
     * @return
     */
    std::unique_ptr<TMission> MainMenu(
        std::unique_ptr<TMission> mission,
        MyList<TWeapon>&& weapons_,
        MyList<std::unique_ptr<TShip>>&& ships_,
        std::istream& file);
public:
    /*!
     * Промежуточная функция. Запускает MainMenu
     * Принимает миссию после загрузки из файла, список доступных для покуки орудий и кораблей
     * Возврашает миссию после всех покупок
     * @return
     */
    std::unique_ptr<TMission> Shop(
        std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>&& data,
        std::istream& file);
};
#endif //LAB4_TSHOP_H
