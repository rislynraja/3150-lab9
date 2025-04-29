#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include "LinkedList2.cpp"

TEST_CASE("Demo") {
    LinkedList list;

    list.SERVER_buildCircularLinkedList();  // step 1
    printf("------------RUNNING SERVER PRINT NOW-----------\n"); // for making the output easier to read
    list.SERVER_printLinkedList();          // step 2
    printf("----------RUNNING CLIENT PRINT NOW-------------\n"); // for making the output easier to read
    list.CLIENT_printLinkedList();          // step 3
    printf("----------RUNNING DELETE CLL NOW-------------\n"); // for making the output easier to read
    list.SERVER_deleteCircularLinkedList(); // step 4
    printf("----------RUNNING CLIENT PRINT NOW-------------\n"); // for making the output easier to read
    list.CLIENT_printLinkedList();          // step 5 - should get [nothing]

    CHECK(true); // check to make test pass if everything runs
}

TEST_CASE("Testing SERVER_buildCircularLinkedList") {
    LinkedList list2;
    list2.SERVER_buildCircularLinkedList(); // build
    auto names = list2.getNodeNames(); // get
    CHECK(names.size() == 6);
    CHECK(names[1] == "one");
    CHECK(names[2] == "two");
    CHECK(names[3] == "three");
}

TEST_CASE("Testing SERVER_deleteCircularLinkedList") {
    LinkedList list3;
    list3.SERVER_buildCircularLinkedList();
    CHECK(list3.getNodeNames().size() == 6);
    CHECK(list3.useCountAtRoot() > 1); // root and tail both reference it
    list3.SERVER_deleteCircularLinkedList();
    CHECK(list3.useCountAtRoot() <= 1); // root is deleted
}
