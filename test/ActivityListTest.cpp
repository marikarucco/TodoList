#include "gtest/gtest.h"
#include "../ActivityList.h"

TEST(ActivityList, Constructor) {
    ActivityList l ("mylist");
    ASSERT_EQ("mylist", l.getName());
    ASSERT_FALSE("list"== l.getName());
}

TEST(ActivityList, AddActivity) {
    ActivityList l ("mylist");
    Activity a (1, "Fare la spesa", false, 40);
    l.addActivity(a);
    ASSERT_FALSE(l.getSize()== 0);
}

TEST(ActivityList, RemoveActivity) {
    ActivityList l ("mylist");
    Activity a (1, "Fare la spesa", false, 40);
    Activity b (2, "Stirare", true, 25);
    l.addActivity(a);
    l.addActivity(b);
    l.removeActivity(a);
    ASSERT_EQ(1, l.getSize());
}


TEST(ActivityList, SearchActivity) {
    ActivityList l ("mylist");
    Activity a (1, "Preparare la colazione", true, 5);
    Activity b (2, "Sistemare il giardino", false, 50);
    l.addActivity(a);
    l.addActivity(b);
    Activity c (3, "Rifare il letto", false, 2);
    ASSERT_FALSE(l.searchActivity(c));
    ASSERT_EQ(l.searchActivity(a), true);

}

TEST(ActivityList, SearchActivityByDescription) {
    ActivityList l ("mylist");
    Activity a (1, "Preparare la colazione", true, 5);
    Activity b (2, "Sistemare il giardino", false, 50);
    l.addActivity(a);
    l.addActivity(b);
    Activity c = l.searchActivityByDescription("Preparare la colazione");
    ASSERT_EQ(a.getId(), c.getId());
    ASSERT_EQ(a.getDescription(), c.getDescription());
    ASSERT_EQ(a.getDone(), c.getDone());
    ASSERT_EQ(a.getDuration(), c.getDuration());
}


TEST(ActivityList, GetNumActivitiesToDo) {
    ActivityList l ("mylist");
    Activity a (1, "Uscire per commissioni", true, 20);
    Activity b (2, "Fare la spesa", false, 40);
    Activity c (3, "Fare un dolce", false, 20);
    Activity d (4, "Fare la lavatrice", true, 15);
    l.addActivity(a);
    l.addActivity(b);
    l.addActivity(c);
    l.addActivity(d);
    ASSERT_EQ(2, l.getNumActivitiesToDo());
    ASSERT_FALSE(l.getNumActivitiesToDo() == 4);
}

TEST(ActivityList, GetListOfUndone) {
    ActivityList l ("mylist");
    Activity a(1, "Spolverare i mobili", false, 35);
    Activity b(2, "Sistemare i vestiti", false, 10);
    Activity c(3, "Uscire per commissioni", false, 45);
    Activity d(4, "Fare un dolce", false, 20);
    l.addActivity(a);
    l.addActivity(b);
    l.addActivity(c);
    l.addActivity(d);
    Activity e (5, "Fare la lavatrice", true, 10);
    ASSERT_FALSE(5 == (int)l.getListOfUndone().size());
    ASSERT_EQ(4, (int)l.getListOfUndone().size());
}

TEST(ActivityList, ModifyActivity) {
    ActivityList l ("mylist");
    Activity a (1, "Spolverare i mobili", false, 35);
    l.addActivity(a);
    l.modifyActivity(a, 1, "Sistemare i vestiti", true, 20);
    ASSERT_EQ("Sistemare i vestiti", a.getDescription());
    ASSERT_EQ(1, l.getSize());
}


TEST(ActivityList, SaveListToFile) {
    ActivityList l ("mylist");
    Activity b(1, "Fare la spesa", false, 20);
    Activity c(2, "Cercare ricette", false, 15);
    Activity d(3, "Fare un dolce", false, 30);
    Activity e(4, "Portare il dolce alle amiche", false, 50);
    l.addActivity(b);
    l.addActivity(c);
    l.addActivity(d);
    l.addActivity(e);
    l.saveList("mytodolist.txt");
    l.readList("mytodolist.txt", l.getSize());
    ASSERT_EQ(4, l.getSize());
}
