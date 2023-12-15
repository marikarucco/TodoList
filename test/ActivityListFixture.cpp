#include "gtest/gtest.h"
#include "../ActivityList.h"

class ActivityListSuite : public ::testing::Test {

protected:
    void SetUp() override{
        a.setId(1);
        a.setDescription("Fare la lavatrice");
        a.setDone(false);
        b.setId(2);
        b.setDescription("Stirare e riordinare");
        b.setDone(true);
        l.addActivity(a);
        l.addActivity(b);

    }
    ActivityList l;
    Activity a;
    Activity b;
};


TEST_F(ActivityListSuite, TestAddActivity) {
    Activity c(5, "Comprare la pasta", false);
    l.addActivity(c);
    ASSERT_EQ(3, l.getSize());
    ASSERT_EQ(l.activitiesToDo.back().getDescription(), "Comprare la pasta");
}


TEST_F(ActivityListSuite, TestRemoveActivity) {
    l.removeActivity(b);
    ASSERT_EQ(1, l.getSize());
    ASSERT_FALSE(l.activitiesToDo.back().getDescription() == "Stirare e riordinare");
}


TEST_F(ActivityListSuite, TestSearchActivity) {
    Activity e (5, "Compare la pasta", false);
    l.addActivity(e);
    l.removeActivity(e);
    ASSERT_FALSE(l.searchActivity(e));
    ASSERT_EQ(l.searchActivity(b), true);

}

TEST_F(ActivityListSuite, TestModifyActivity){
    l.modifyActivity(a, 1, "Fare la spesa", true);
    ASSERT_EQ(a.getDescription(), "Fare la spesa");
    ASSERT_FALSE(!a.getDone());
}

TEST_F(ActivityListSuite, TestGetActivitiesToDo){
    ASSERT_EQ(1, l.getActivitiesToDo());
    Activity c (3, "Comprare vestiti", false);
    l.addActivity(c);
    ASSERT_EQ(2, l.getActivitiesToDo());
}


TEST_F(ActivityListSuite, TestGetSize) {
    ASSERT_EQ(2, l.getSize());
    Activity a(1, "Rifare il letto", false);
    l.addActivity(a);
    ASSERT_FALSE(2 == l.getSize());
}

TEST_F(ActivityListSuite, TestSaveList){
    Activity c (4, "Sistemare il giardino", false);
    l.addActivity(c);
    l.saveList("test.txt");
    l.readList("test.txt", l.getSize());
    ASSERT_FALSE(l.activitiesToDo.front().getId()==2);
    ASSERT_FALSE(l.activitiesToDo.front().getDescription()=="Sistemare");
    ASSERT_FALSE(l.getSize() == 10);
    ASSERT_EQ(3, l.getSize());
}