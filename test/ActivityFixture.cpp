#include "gtest/gtest.h"
#include "../Activity.h"

class ActivitySuite : public ::testing::Test {

protected:
    virtual void SetUp(){
    a.setId(1);
    a.setDescription("lavatrice");
    }
    Activity a;
};

TEST_F (ActivitySuite, TestConstructor){
    ASSERT_EQ(1, a.getId());
    ASSERT_EQ("lavatrice", a.getDescription());

}
