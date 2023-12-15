#include "gtest/gtest.h"
#include "../Activity.h"


TEST(Activity, Constructor) {
    Activity a(1, "Fare un dolce", false);
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("Fare un dolce", a.getDescription());
    ASSERT_FALSE("dolce" == a.getDescription());
    ASSERT_FALSE(a.getDone()==true);
}

TEST(Activity, EqOperator) {
    Activity a(1, "Fare la spesa", true);
    Activity b(1, "Fare la spesa", false);
    ASSERT_FALSE(a==b);
}

TEST(Activity, DifOperator) {
    Activity a(1, "Fare la lavatrice", false);
    Activity b(1, "Fare la lavatrice", false);
    ASSERT_FALSE(a!=b);
}

TEST(Activity, MinOperator) {
    Activity a(1, "Fare la lavatrice", false);
    Activity b(2, "Fare la spesa", false);
    ASSERT_FALSE(!(a<b));
}
