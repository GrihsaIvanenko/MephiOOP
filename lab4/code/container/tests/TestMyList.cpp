//
// Created by grigorijivanenko on 17.12.22.
//

#include "gtest/gtest.h"

#include "../code/MyList.h"

TEST(MyList, InitConstructorAndAssign) {
    MyList<int> list;
    list.insert(3, list.begin());
    list.insert(4, list.end());
    ASSERT_EQ(list.size(), 2);

    MyList<int> list3(std::move(list));
    ASSERT_EQ(list3.size(), 2);
    ASSERT_EQ(list.size(), 0);
    list = std::move(list3);
    ASSERT_EQ(list3.size(), 0);
}

TEST(MyList, InsertErase) {
    MyList<int> list1;
    list1.insert(2, list1.begin());
    ASSERT_EQ(list1.size(), 1);
    ASSERT_EQ(list1.getById(0), 2);

    MyList<int> list2;
    list2.insert(2, list2.end());
    ASSERT_EQ(list2.size(), 1);
    ASSERT_EQ(list2.getById(0), 2);

    list1.insert(3, list1.begin());
    ASSERT_EQ(list1.size(), 2);
    ASSERT_EQ(list1.getById(0), 3);
    ASSERT_EQ(list1.getById(1), 2);

    auto it = list1.begin();
    ++it;
    list1.insert(4, it);
    ASSERT_EQ(list1.size(), 3);
    ASSERT_EQ(list1.getById(0), 3);
    ASSERT_EQ(list1.getById(1), 4);
    ASSERT_EQ(list1.getById(2), 2);

    list1.erase(it);
    ASSERT_EQ(list1.size(), 2);
    ASSERT_EQ(list1.getById(0), 3);
    ASSERT_EQ(list1.getById(1), 2);

    list1.erase(it);
    ASSERT_EQ(list1.size(), 1);
    ASSERT_EQ(list1.getById(0), 3);
}