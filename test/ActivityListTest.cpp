#include "gtest/gtest.h"
#include "../ActivityList.h"

TEST(ActivityList, DefaultConstructor) {
    ActivityList lista;
    ASSERT_EQ(0, lista.activitiesToDo.size());
}


TEST(ActivityList, AddActivity) {
    ActivityList lista;
    lista.addActivity(1, "fare_la_spesa");
    ASSERT_FALSE(lista.activitiesToDo.size() == 0);
}


TEST(ActivityList, SaveListToFile) {
    ActivityList lista;
    lista.addActivity(1, "spesa");
    lista.addActivity(2, "dolce");
    lista.addActivity(3, "lavatrice");
    lista.addActivity(4, "stendere");
    lista.saveList("mytodolist.txt");
    lista.readList("mytodolist.txt", 4);
    ASSERT_EQ(4, lista.activitiesToDo.size());
    ASSERT_EQ(lista.activitiesToDo.front().getId(), 1);
    ASSERT_EQ(lista.activitiesToDo.front().getDescription(), "spesa");
}
