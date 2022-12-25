//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TIMEHOLDER_H
#define LAB4_TIMEHOLDER_H

#include <time.h>

/*!
 * \brief Класс, отвечающий за время в нашей программе.
 */

class TimeHolder {
private:
    inline static clock_t PrevMoment_ = 0;
    inline static clock_t ClocksFromStart_ = 0;
    void UpdateClocks();
    /*!
     * Устанавливаем, сколько раз в секунду будет обновляться происходящее в игре.
     */
    const double FPS = 4;
public:
    /*!
     * Начинает отчет времени
     */
    void Start();

    /*!
     * Возвращает номер текущего кадра.
     * @return
     */
    virtual int GetTact();
};

#endif //LAB4_TIMEHOLDER_H
