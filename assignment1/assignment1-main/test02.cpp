#include <iostream>
#include "linkedlist.h"
#include "catch.hpp"
using namespace std;

TEST_CASE( "Test 02", "Assignment 1" )
{
    LinkedList L;   // this is my list
    int x;     // to hold a removed element

    REQUIRE(L.isEmpty());
    L.addFront(9);
    L.addFront(8);
    L.addFront(6);
    L.addFront(5);

    REQUIRE(L.length() == 4);
    L.displayAll();

    L.insertAt(0, 4);
    L.displayAll();
    L.insertAt(3, 7);
    L.displayAll();
    L.insertAt(6, 10);
    REQUIRE(L.length() == 7);
    L.displayAll();

    bool success = L.insertAt(9, 12);
    REQUIRE(!success);
    L.displayAll();

    success = L.insertAt(0, 0);
    REQUIRE(success);
    L.displayAll();

    success = L.deleteAt(1, x);
    REQUIRE(x == 4);

    success = L.deleteAt(6, x);
    REQUIRE((x == 10 && success));

    L.displayAll();
    success = L.deleteAt(3, x);
    cout << "x = " << x << endl;
    REQUIRE(( x == 7));
    L.displayAll();

    success = L.deleteAt(5, x);
    REQUIRE(!success);

    success = L.deleteAt(-1, x);
    REQUIRE(!success);

    while(!L.isEmpty()) {
        L.deleteRear(x);
        cout << "Removed: " << x << endl;
    }
    success = L.insertAt(-1, 0);
    REQUIRE(!success);

    success = L.deleteFront(x);
    REQUIRE(!success);

    success = L.deleteRear(x);
    REQUIRE(!success);

    success = L.deleteRear(x);
    REQUIRE(!success);
}
