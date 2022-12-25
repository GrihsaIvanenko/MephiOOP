//
// Created by grigorijivanenko on 18.12.22.
//

#ifndef LAB4_TLEVELREADER_H
#define LAB4_TLEVELREADER_H

#include "TMission.h"

#include <memory>
#include <iostream>

/*!
 * \brief Класс, отвечающий за загрузку уровня из файла
 */

class TLevelReader {
public:
    /*!
     * Функция, считывающая одно число.
     * Вначале идет описание(what), затем двоеточие, пробел, оставшийся суффикс будет переводиться в число
     * Если префикс не подходит под заданный формат, вылетит ошибка-строка
     * Если суффикс не является числом, вылетит ошибка-строка
     */
    int ReadInt(std::istream& file, const std::string& what);

    /*!
     * Функция, считывающая одну строку.
     * Вначале идет описание(what), затем двоеточие, пробел, оставшийся суффикс будет результатом ввода
     * Если префикс не подходит под заданный формат, вылетит ошибка-строка
     */
    std::string ReadString(std::istream& file, const std::string& what);

    /*!
     * Функция, считывающая пустую строку
     */
    void ReadEmpty(std::istream& file);

    /*!
     * Считывает информацию о капитане - 4 строки
     * Имя капитана - (CapitanName)
     * Фамилия капитана - (CapitanSurname)
     * Отчество капитана - (CapitanPatronymic)
     * Ранг капитана - (CapitanRank)
     */
    TCapitanInfo ReadCapitanInfo(std::istream& file);

    /*!
     * Считывает информацию об орудии - числа
     * Тип орудия - (WeaponType)
     * Урон орудия - (Damage)
     * Перезарядку орудия - (CallDown)
     * Дальность стрельбы - (Range)
     * Количество выстрелов - (ShotsTotal)
     * Цена - (Cost)
     */
    TWeapon ReadWeapon(std::istream& file);

    /*!
     * Считывает информацию об корабле - числа
     * Тип корабля - число 1 2 или 3. Все строки идут подряд. 1 - грузовой. 2 - с орудиями. 3 - и с грузом и с орудиями.
     *
     * Если тип корабля 1
     * Тип корабля - (ShipType) - 1
     * Номер введенного ранее капитана - (CapitanInfoId)
     * Максимальная скорость - (MaxSpeed)
     * Количество здоровья - (HPTotal)
     * Цена - (Cost)
     * Максимальный вес - (WeightTotal)
     * Коэфф замедления, во столько раз уменьшится скорость при полной загрузке, ЦЕЛОЕ ЧИСЛО - (SlowK)
     *
     * Если тип корабля 2
     * Тип корабля - (ShipType) - 2
     * Номер введенного ранее капитана - (CapitanInfoId)
     * Максимальная скорость - (MaxSpeed)
     * Количество здоровья - (HPTotal)
     * Цена - (Cost)
     * Номер орудия спереди корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon1)
     * Номер орудия сзади корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon2)
     * Номер орудия слева корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon3)
     * Номер орудия спрпва корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon4)
     *
     * Если тип корабля 3
     * Тип корабля - (ShipType) - 3
     * Номер введенного ранее капитана - (CapitanInfoId)
     * Максимальная скорость - (MaxSpeed)
     * Количество здоровья - (HPTotal)
     * Цена - (Cost)
     * Максимальный вес - (WeightTotal)
     * Коэфф замедления, во столько раз уменьшится скорость при полной загрузке, ЦЕЛОЕ ЧИСЛО - (SlowK)
     * Номер орудия спереди корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon1)
     * Номер орудия сзади корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon2)
     * Номер орудия слева корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon3)
     * Номер орудия спрпва корабля. Нумерация с ЕДИНИЦЫ. 0 если нет орудия.  - (Weapon4)
    */
    std::unique_ptr<TShip> ReadShip(std::istream& file, MyList<TWeapon>& weapons, const MyList<TCapitanInfo>& capitans);

    /*!
     * Функция, считывающая базу пиратов
     * Формат:
     * X координата - (Base_X)
     * Y координата - (Base_Y)
     * Тип базы - (Base_Type) 1 - начало миссии, 2 - конец миссии
     */
    TBase ReadBase(std::istream& file, const std::string& what);

    /*!
     * Функция, считывающая список чисел
     * Вначале количество.
     * Пустая строка. Затем число(what) + Пустая строка.
     */
    MyList<int> ReadInts(std::istream& file, const std::string& what);

    /*!
     * Функция, считывающая список капитанов
     * Вначале количество.
     * Пустая строка. Затем капитан + Пустая строка.
     */
    MyList<TCapitanInfo> ReadCapitanInfos(std::istream& file);

    /*!
     * Функция, считывающая список орудий
     * Вначале количество.
     * Пустая строка. Затем орудие + Пустая строка.
     */
    MyList<TWeapon> ReadWeapons(std::istream& file);

    /*!
     * Функция, считывающая список баз кораблей
     * Вначале количество.
     * Пустая строка. Затем корабль + Пустая строка.
     */
    MyList<std::unique_ptr<TShip>> ReadShips(std::istream& file, MyList<TWeapon>& weapons, const MyList<TCapitanInfo>& capitans);

    /*!
     * Функция, считывающая спавнер пиратов на пиратской базе
     * Формат:
     * Номер корабля, который будет спавнится. Обязано быть TWarShip или его наследником - (ShipSpawnType)
     * Сколько всего кораблей заспавнит дескриптор - (SpamCount)
     * Раз в сколько кадров будет появляться новый корабль (LoopTime)
     *
     * Спавн зависит от числа кадров, а не секунд, для удобства тестирования и наблюдения за происходящим
     */
    TSpawnDescriptor ReadSpawnDescriptor(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships);

    /*!
     * Функция, считывающая список баз дескрипторов спавна
     * Вначале количество.
     * Пустая строка. Затем спавнер + Пустая строка.
     */
    MyList<TSpawnDescriptor> ReadSpawnDescriptors(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships);

    /*!
     * Функция, считывающая базу пиратов
     * Формат:
     * X координата - (Base_X)
     * Y координата - (Base_Y)
     * Тип базы - (Base_Type) обязано быть тройкой, т.к. именно такой тип у базы пиратов
     * Номер дескриптора, отвечающего за спавн пиратов - (DescriptorNumber)
     */
    TPirateBase ReadPirateBase(std::istream& file, const MyList<TSpawnDescriptor>& desctiptors);

    /*!
     * Функция, считывающая список баз пиратов
     * Вначале количество.
     * Пробел. Затем база + пробел.
     */
    MyList<TPirateBase> ReadPirateBases(std::istream& file, const MyList<TSpawnDescriptor>& descriptots);
public:
    /*!
     * Общая функция для считывания уровня из файла
     * Принимает поток для считывания
     * Возвращает описание миссии, список орудий и кораблей, доступных для покупки.
     *
     * Формат файла с уровнем:
     * Ввод капитанов
     * Ввод орудий
     * Ввод кораблей
     * всего денег - (moneyTotal)
     * вес для транспортировки - (weightTotal)
     * вес, необходимый для прохождения уровня - (weightNeedToPass)
     * Ширина карты в клетках - (width)
     * Высота карты в клетках - (height)
     * Пустая строка
     * База А
     * Пустая строка
     * База B
     * Пустая строка
     * Ввод спавнеров
     * Ввод пиратских баз
     */
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
        ReadMissionInfoFromStream(std::istream& file);
};

#endif //LAB4_TLEVELREADER_H
