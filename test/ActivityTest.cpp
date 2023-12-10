#include "gtest/gtest.h"
#include "../Activity.h"


TEST(Activity, Constructor) {
    Activity a(1, "dolce");
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("dolce", a.getDescription());
}