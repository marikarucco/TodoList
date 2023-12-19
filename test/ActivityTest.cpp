#include "gtest/gtest.h"
#include "../Activity.h"


TEST(Activity, Constructor) {
    Activity a(1, "Fare un dolce", false, 20);
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("Fare un dolce", a.getDescription());
    ASSERT_FALSE("dolce" == a.getDescription());
    ASSERT_FALSE(a.getDone()==true);
    ASSERT_EQ(20, a.getDuration());
}

TEST(Activity, EqOperator) {
    Activity a(1, "Fare la spesa", true, 45);
    Activity b(1, "Fare la spesa", false, 45);
    ASSERT_FALSE(a==b);
}

TEST(Activity, DifOperator) {
    Activity a(1, "Fare la lavatrice", false, 20);
    Activity b(1, "Fare la lavatrice", false, 20);
    ASSERT_FALSE(a!=b);
}

TEST(Activity, MinOperator) {
    Activity a(1, "Fare la lavatrice", false, 20);
    Activity b(2, "Fare la spesa", false, 45);
    ASSERT_FALSE(!(a<b));
}

