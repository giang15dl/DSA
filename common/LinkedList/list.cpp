#include <iostream>
#include "list.hpp"

int main() {
    list l;
    l.print();
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.insert(1, 5);
    l.insert(2, 6);
    l.insert(3, 7);
    l.insert(4, 8);
    l.push_back(9);
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.print();
    l.pop_front();
    l.print();
    l.pop_back();
    l.print();
    l.erase(5);
    l.print();

    return 0;
}