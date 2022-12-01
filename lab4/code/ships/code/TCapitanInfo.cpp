//
// Created by grigorijivanenko on 29.11.22.
//

#include "TCapitanInfo.h"

TCapitanInfo::TCapitanInfo(): Name_(""), Surname_(""), Patronymic_(""), Rank_("") { }

TCapitanInfo::TCapitanInfo(
        const std::string& name, const std::string& surname, const std::string& patronymic, const std::string& rank)
    : Name_(name)
    , Surname_(surname)
    , Patronymic_(patronymic)
    , Rank_(rank)
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

bool TCapitanInfo::operator == (const TCapitanInfo& other) const {
    return
        Name_ == other.Name_ &&
        Surname_ == other.Surname_ &&
        Patronymic_ == other.Patronymic_ &&
        Rank_ == other.Rank_;
}

void TCapitanInfo::SetName(const std::string& name) {
    Name_ = name;
}

void TCapitanInfo::SetSurname(const std::string& surname) {
    Surname_ = surname;
}

void TCapitanInfo::SetPatronymic(const std::string& patronymic) {
    Patronymic_ = patronymic;
}

void TCapitanInfo::SetRank(const std::string& rank) {
    Rank_ = rank;
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
