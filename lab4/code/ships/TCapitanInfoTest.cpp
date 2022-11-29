//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "TCapitanInfo.h"

std::vector<std::string> GetFields(const TCapitanInfo& capitanInfo) {
    return {capitanInfo.GetName(), capitanInfo.GetSurname(), capitanInfo.GetPatronymic(), capitanInfo.GetRank()};
}

TEST(TCapitanInfo, Constructors) {
    TCapitanInfo empty;
    std::vector<std::string> tmp = {"", "", "", ""};
    ASSERT_EQ(GetFields(empty), tmp);

    tmp = {"name", "surname", "patronymic", "ranl"};
    TCapitanInfo one(tmp[0], tmp[1], tmp[2], tmp[3]);
    ASSERT_EQ(GetFields(one), tmp);

    TCapitanInfo two(one);
    ASSERT_EQ(GetFields(one), GetFields(two));

    two = empty;
    ASSERT_EQ(GetFields(empty), GetFields(two));
}

TEST(TCapitanInfo, Setters) {
    TCapitanInfo capitanInfo;
    std::vector<std::string> now_state = {"", "", "", ""};
    std::vector<std::string> tmp = {"name", "surname", "patronymic", "rank"};

    capitanInfo.SetName(tmp[0]);
    now_state[0] = tmp[0];
    ASSERT_EQ(GetFields(capitanInfo), now_state);

    capitanInfo.SetSurname(tmp[1]);
    now_state[1] = tmp[1];
    ASSERT_EQ(GetFields(capitanInfo), now_state);

    capitanInfo.SetPatronymic(tmp[2]);
    now_state[2] = tmp[2];
    ASSERT_EQ(GetFields(capitanInfo), now_state);

    capitanInfo.SetRank(tmp[3]);
    now_state[3] = tmp[3];
    ASSERT_EQ(GetFields(capitanInfo), now_state);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}