//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TCAPITANINFO_H
#define LAB4_TCAPITANINFO_H

#include <string>

/*!
 * \brief Класс для хранения информации о капитане.
 */

class TCapitanInfo {
private:
    std::string Name_;
    std::string Surname_;
    std::string Patronymic_;
    std::string Rank_;
public:
    TCapitanInfo();
    TCapitanInfo(
            const std::string& name, const std::string& surname, const std::string& patronymic, const std::string& rank);
    TCapitanInfo(const TCapitanInfo& other);
    TCapitanInfo& operator = (const TCapitanInfo& other);
    bool operator ==(const TCapitanInfo& other) const;

    void SetName(const std::string& name);
    void SetSurname(const std::string& surname);
    void SetPatronymic(const std::string& patronymic);
    void SetRank(const std::string& rank);

    std::string GetName() const;
    std::string GetSurname() const;
    std::string GetPatronymic() const;
    std::string GetRank() const;
};

#endif //LAB4_TCAPITANINFO_H
