#include "gtest/gtest.h"
#include "../Activity.h"

class ActivitySuite : public ::testing::Test {

protected:
    void SetUp() override{
    a.setId(1);
    a.setDescription("Fare la lavatrice");
    a.setDone(true);
    }
    Activity a;
};

TEST_F (ActivitySuite, TestConstructor){
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("Fare la lavatrice", a.getDescription());
}

TEST_F (ActivitySuite, TestEqOperator){
    Activity b(2, "Preparare la cena", false);
    ASSERT_FALSE(a==b);
}


TEST_F(ActivitySuite, TestDifOperator) {
    Activity c(1, "Fare la lavatrice", true);
    ASSERT_FALSE(a!=c);
}
