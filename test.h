//
// Created by tangb on 4/23/2020.
//

#ifndef ITERATOR_TEST_H
#define ITERATOR_TEST_H
#include <iostream>
#include <cassert>
#include "list.h"
using namespace std;
struct info {
    int _day;
    int _week;
    info (const int& day, const int& week):_day(day), _week(week){};
    friend ostream& operator << (ostream& outs, const info& i){
        outs<< "[" << i._day <<", " << i._week << "]";
        return outs;
    }
};
void test();
void test_struct();
void print_app (const List<int> & l, List<int>::Iterator cursor);
#endif //ITERATOR_TEST_H
