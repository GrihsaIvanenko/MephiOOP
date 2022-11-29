//
// Created by grigorijivanenko on 29.11.22.
//

#include "TCapitanInfo.h"

TCapitanInfo::TCapitanInfo(): Name_(""), Surname_(""), Patronymic_(""), Rank_("") { }

TCapitanInfo::TCapitanInfo(
        const std::string& Name, const std::string& Surname, const std::string& Patronymic, const std::string& Rank)
    : Name_(Name)
    , Surname_(Surname)
    , Patronymic_(Patronymic)
    , Rank_(Rank)
{ }

TCapitanInfo::TCapitanInfo(const TCapitanInfo& other)
    : Name_(other.Name_)
    , Surname_(other.Surname_)
    , Patronymic_(other.Patronymic_)
    , Rank_(other.Rank_)
{ }

TCapitanInfo& TCapitanInfo::operator = (const TCapitanInfo& other) {
    Name_ = other.Name_;
    Surname_ = other.Surname_;
    Patronymic_ = other.Patronymic_;
    Rank_ = other.Rank_;
    return *this;
}

void TCapitanInfo::SetName(const std::string& Name) {
    Name_ = Name;
}

void TCapitanInfo::SetSurname(const std::string& Surname) {
    Surname_ = Surname;
}

void TCapitanInfo::SetPatronymic(const std::string& Patronymic) {
    Patronymic_ = Patronymic;
}

void TCapitanInfo::SetRank(const std::string& Rank) {
    Rank_ = Rank;
}

std::string TCapitanInfo::GetName() const {
    return Name_;
}

std::string TCapitanInfo::GetSurname() const {
    return Surname_;
}

std::string TCapitanInfo::GetPatronymic() const {
    return Patronymic_;
}

std::string TCapitanInfo::GetRank() const {
    return Rank_;
}
