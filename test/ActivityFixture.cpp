#include "gtest/gtest.h"
#include "../Activity.h"

class ActivitySuite : public ::testing::Test {

protected:
    void SetUp() override{
    a.setId(1);
    a.setDescription("Fare la lavatrice");
    a.setDone(true);
    a.setDuration(20);
    }
    Activity a;
};

TEST_F (ActivitySuite, TestConstructor){
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("Fare la lavatrice", a.getDescription());
    ASSERT_FALSE(!a.getDone());
    ASSERT_FALSE(15 == a.getDuration());
}

TEST_F (ActivitySuite, TestEqOperator){
    Activity b(2, "Preparare la cena", false, 25);
    ASSERT_FALSE(a==b);
}


TEST_F(ActivitySuite, TestDifOperator) {
    Activity c(1, "Fare la lavatrice", true, 20);
    ASSERT_FALSE(a!=c);
}


TEST_F(ActivitySuite, TestMinOperator) {
    Activity d (2, "Uscire per commissioni", true, 100);
    ASSERT_FALSE(d<a);
}
