//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "../code/TCapitanInfo.h"

bool operator == (const TCapitanInfo& lhs, const std::vector<std::string>& rhs) {
    return
            lhs.GetName() == rhs[0] &&
            lhs.GetSurname() == rhs[1] &&
            lhs.GetPatronymic() == rhs[2] &&
            lhs.GetRank() == rhs[3];
}

TEST(TCapitanInfo, Constructors) {
    TCapitanInfo empty;
    std::vector<std::string> tmp = {"", "", "", ""};
    ASSERT_EQ(empty, tmp);

    tmp = {"name", "surname", "patronymic", "ranl"};
    TCapitanInfo one(tmp[0], tmp[1], tmp[2], tmp[3]);
    ASSERT_EQ(one, tmp);

    TCapitanInfo two(one);
    ASSERT_EQ(one, two);

    two = empty;
    ASSERT_EQ(empty, two);
}

TEST(TCapitanInfo, Setters) {
    TCapitanInfo capitanInfo;
    std::vector<std::string> now_state = {"", "", "", ""};
    std::vector<std::string> tmp = {"name", "surname", "patronymic", "rank"};

    capitanInfo.SetName(tmp[0]);
    now_state[0] = tmp[0];
    ASSERT_EQ(capitanInfo, now_state);

    capitanInfo.SetSurname(tmp[1]);
    now_state[1] = tmp[1];
    ASSERT_EQ(capitanInfo, now_state);

    capitanInfo.SetPatronymic(tmp[2]);
    now_state[2] = tmp[2];
    ASSERT_EQ(capitanInfo, now_state);

    capitanInfo.SetRank(tmp[3]);
    now_state[3] = tmp[3];
    ASSERT_EQ(capitanInfo, now_state);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}