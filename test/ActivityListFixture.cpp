#include "gtest/gtest.h"
#include "../ActivityList.h"

class ActivityListSuite : public ::testing::Test {

protected:
    void SetUp() override{
        l.setName("mylist");
        a.setId(1);
        a.setDescription("Fare la lavatrice");
        a.setDone(false);
        a.setDuration(20);
        b.setId(2);
        b.setDescription("Stirare e riordinare");
        b.setDone(true);
        b.setDuration(35);
        l.addActivity(a);
        l.addActivity(b);

    }
    ActivityList l;
    Activity a;
    Activity b;
};


TEST_F(ActivityListSuite, TestAddActivity) {
    Activity c(5, "Comprare la pasta", false, 10);
    l.addActivity(c);
    ASSERT_EQ(3, l.getSize());
    ASSERT_EQ(l.getActivitiesToDo().back().getDescription(), "Comprare la pasta");
}


TEST_F(ActivityListSuite, TestRemoveActivity) {
    l.removeActivity(b);
    ASSERT_EQ(1, l.getSize());
    ASSERT_FALSE(l.getActivitiesToDo().back().getDescription() == "Stirare e riordinare");
}


TEST_F(ActivityListSuite, TestSearchActivity) {
    Activity e (5, "Compare la pasta", false, 20);
    l.addActivity(e);
    l.removeActivity(e);
    ASSERT_FALSE(l.searchActivity(e));
    ASSERT_EQ(l.searchActivity(b), true);

}

TEST_F(ActivityListSuite, TestSearchActivityByDescription) {
    ASSERT_EQ(l.searchActivityByDescription("Fare la lavatrice"), a);
}

TEST_F(ActivityListSuite, TestGetNumActivitiesToDo){
    ASSERT_EQ(1, l.getNumActivitiesToDo());
    Activity c (3, "Comprare vestiti", false, 40);
    l.addActivity(c);
    ASSERT_EQ(2, l.getNumActivitiesToDo());
}


TEST_F(ActivityListSuite, TestGetListOfUndone) {
    l.modifyActivity(b, 2, "Stirare e riordinare", false, 35);
    ASSERT_EQ(l.getListOfUndone().size(), l.getSize());
}

TEST_F(ActivityListSuite, TestModifyActivity){
    l.modifyActivity(a, 1, "Fare la spesa", true, 40);
    ASSERT_EQ(l.getActivitiesToDo().back().getDescription(), "Fare la spesa");
    ASSERT_FALSE(!l.getActivitiesToDo().back().getDone());
}


TEST_F(ActivityListSuite, TestGetSize) {
    ASSERT_EQ(2, l.getSize());
    Activity a(1, "Rifare il letto", false, 5);
    l.addActivity(a);
    ASSERT_FALSE(2 == l.getSize());
}

TEST_F(ActivityListSuite, TestSaveList){
    Activity c (4, "Sistemare il giardino", false, 40);
    l.addActivity(c);
    l.saveList("test.txt");
    l.readList("test.txt", l.getSize());
    ASSERT_FALSE(l.getActivitiesToDo().front().getId()==2);
    ASSERT_FALSE(l.getActivitiesToDo().front().getDescription()=="Sistemare");
    ASSERT_FALSE(l.getSize() == 10);
    ASSERT_EQ(3, l.getSize());
}