#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "LinkedList.cpp"
#include "./include/doctest.h"

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
    auto names = list2.getServerNodeNames(); // get from server
    CHECK(names.size() == 6);
    CHECK(names[0] == "zero");
    CHECK(names[5] == "five");
}

TEST_CASE("Testing SERVER_buildCircularLinkedList 2") {
    LinkedList list3;
    list3.SERVER_buildCircularLinkedList();
    auto names = list3.getClientNodeNamesUsingWeakPtrs();
    CHECK(names.size() == 6);
    CHECK(names[2] == "two");
}

TEST_CASE("Testing SERVER_deleteCircularLinkedList") {
    LinkedList list4;
    list4.SERVER_buildCircularLinkedList();
    list4.SERVER_deleteCircularLinkedList();
    auto names = list4.getClientNodeNamesUsingWeakPtrs();
    CHECK(names.size() <= 1); 
}