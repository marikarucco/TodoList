#include "gtest/gtest.h"
#include "../ActivityList.h"

class ActivityListSuite : public ::testing::Test {

protected:
    virtual void SetUp(){
        lista.addActivity(1, "lavare");
        lista.addActivity(2, "stendere");
        lista.addActivity(3, "stirare");

    }
    ActivityList lista;
};


TEST_F(ActivityListSuite, TestSaveList){
    lista.addActivity(4, "sistemare");
    lista.saveList("test.txt");
    lista.readList("test.txt", 4);
    ASSERT_FALSE(lista.activitiesToDo.front().getId()==2);
    ASSERT_FALSE(lista.activitiesToDo.front().getDescription()=="sistemare");
    ASSERT_FALSE(lista.activitiesToDo.size() == 10);
    ASSERT_EQ(4, lista.activitiesToDo.size());
}