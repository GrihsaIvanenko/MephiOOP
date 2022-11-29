//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TCAPITANINFO_H
#define LAB4_TCAPITANINFO_H

#include <string>

class TCapitanInfo {
private:
    std::string Name_;
    std::string Surname_;
    std::string Patronymic_;
    std::string Rank_;
public:
    TCapitanInfo();
    TCapitanInfo(
            const std::string& Name, const std::string& Surname, const std::string& Patronymic, const std::string& Rank);
    TCapitanInfo(const TCapitanInfo& other);
    TCapitanInfo& operator = (const TCapitanInfo& other);
    void SetName(const std::string& Name);
    void SetSurname(const std::string& Surname);
    void SetPatronymic(const std::string& Patronymic);
    void SetRank(const std::string& Rank);

    std::string GetName() const;
    std::string GetSurname() const;
    std::string GetPatronymic() const;
    std::string GetRank() const;
};

#endif //LAB4_TCAPITANINFO_H
