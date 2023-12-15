#include "gtest/gtest.h"
#include "../ActivityList.h"

TEST(ActivityList, DefaultConstructor) {
    ActivityList l;
    ASSERT_EQ(0, l.getSize());
}


TEST(ActivityList, Constructor) {
    ActivityList l ("mylist");
    ASSERT_EQ("mylist", l.getName());
    ASSERT_FALSE("list"== l.getName());
}

TEST(ActivityList, AddActivity) {
    ActivityList l;
    Activity a (1, "Fare la spesa", false);
    l.addActivity(a);
    ASSERT_FALSE(l.getSize()== 0);
}


TEST(ActivityList, RemoveActivity) {
    ActivityList l;
    Activity a (1, "Fare la spesa", false);
    Activity b (2, "Stirare", true);
    l.addActivity(a);
    l.addActivity(b);
    l.removeActivity(a);
    ASSERT_EQ(1, l.getSize());
    ASSERT_EQ("Stirare", l.activitiesToDo.front().getDescription());
    ASSERT_FALSE(!l.activitiesToDo.front().getDone());
}


TEST(ActivityList, SearchActivity) {
    ActivityList l;
    Activity a (1, "Preparare la colazione", true);
    Activity b (2, "Sistemare il giardino", false);
    l.addActivity(a);
    l.addActivity(b);
    Activity c (3, "Rifare il letto", false);
    ASSERT_FALSE(l.searchActivity(c));
    ASSERT_EQ(l.searchActivity(a), true);

}


TEST(ActivityList, ModifyActivity) {
    ActivityList l;
    Activity a (1, "Spolverare i mobili", false);
    l.addActivity(a);
    l.modifyActivity(a, 1, "Sistemare i vestiti", true);
    ASSERT_EQ("Sistemare i vestiti", l.activitiesToDo.front().getDescription());
    ASSERT_FALSE(!l.activitiesToDo.front().getDone());
}


TEST(ActivityList, GetActivitiesToDo) {
    ActivityList l;
    Activity a(1, "Spolverare i mobili", false);
    Activity b(2, "Sistemare i vestiti", false);
    Activity c(3, "Uscire per commissioni", true);
    Activity d(4, "Fare un dolce", false);
    l.addActivity(a);
    l.addActivity(b);
    l.addActivity(c);
    l.addActivity(d);
    ASSERT_EQ(3, l.getActivitiesToDo());
    ASSERT_FALSE(4 == l.getActivitiesToDo());

}

TEST(ActivityList, SaveListToFile) {
    ActivityList lista;
    Activity b(1, "Fare la spesa", false);
    Activity c(2, "Cercare ricette", false);
    Activity d(3, "Fare un dolce", false);
    Activity e(4, "Portare il dolce alle amiche", false);
    lista.addActivity(b);
    lista.addActivity(c);
    lista.addActivity(d);
    lista.addActivity(e);
    lista.saveList("mytodolist.txt");
    lista.readList("mytodolist.txt", lista.getSize());
    ASSERT_EQ(4, lista.getSize());
    ASSERT_EQ(lista.activitiesToDo.front().getId(), 1);
    ASSERT_EQ(lista.activitiesToDo.front().getDescription(), " Fare la spesa ");
}
