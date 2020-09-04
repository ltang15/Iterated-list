//
// Created by tangb on 4/23/2020.
//
#include "test.h"
#include <ctime>
#include <cstdlib>

void test(){
    List <int> l;

    srand(time(NULL));


    for (int i = 0; i <5 ; i++){
        l.insert_head (rand()%100);
    }

    List<int>::Iterator cursor = l.Begin();
    print_app (l, cursor);

    bool done = false;
    do {

        cout << "Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it" << endl;
        char command;
        cin >> command;

        switch (command) {
            case 'n':
            case 'N': {
                //move to next node
                cursor = cursor.next();
                print_app(l, cursor);
                break;
            }
            case 'p':
            case 'P': {
                //move back to the previous node
                cursor = l.previous(cursor);
                print_app(l, cursor);
                break;
            }


            case 'd':
            case 'D':{
                //delete the current node
                cout << l.delete_this(cursor) << endl;
                cursor = l.Begin();
                print_app (l, cursor);
                break;
            }
            case 'h':
            case 'H': {
                // back to the first node in the list
                cursor = l.Begin();
                print_app(l, cursor);
                break;
            }
            case 'e':
            case 'E': {
                // go the the last node
                cursor = l.previous(l.End());
                print_app(l, cursor);
                break;
            }
            case 's':
            case 'S':{
                //search for the key
                int key;
                cout << "??" << endl;
                cin >> key;
                cursor = l.search(key);
                print_app(l, cursor);
                break;
            }

            case 'a':
            case 'A':{
                int key;
                cout << "??" << endl;
                cin >> key;
                if (cursor == nullptr)
                    cursor = l.insert_head(key);
                else
                    cursor = l.insert_after(cursor, key);
                print_app(l, cursor);
                break;

            }
            case 'b':
            case 'B':{
                int key;
                cout << "??" << endl;
                cin >> key;
                if (cursor == nullptr)
                    cursor = l.insert_head(key);
                else
                    cursor = l.insert_before (cursor, key);
                print_app(l, cursor);
                break;

            }
            case 'x':
            case 'X': {
                // exit program
                done = true;
                break;
            }
        }
    }
    while (!done);

}

void print_app (const List<int> & l, List<int>::Iterator cursor){
    List<int>::Iterator w = l.Begin();
    cout << "..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   .." << endl;
    for (; w != l.End(); w ++){
        if (w == cursor)
            cout << "{" << *cursor << "}" << "->";
        else
            cout << "[" << *w << "]" << "->";
    }

    cout <<"|||" << endl;

}


void test_struct(){
    cout << "Test for some functions: " << endl;

    List <int> l;
    for (int i=0; i< 6; i++){
        l.insert_head(i);
    }
    cout << l << endl;

    List <int> l1(l);
    cout << "Copy constructor: " << l1 << endl;

    List <int> l2;
    l2 = l;
    cout << "Assignment operator: " << l2 << endl;


    l.insert_after(l.search(3), 20);
    cout << "Insert 20 after 3: " << l << endl;

    l.insert_before(l.search(1), 50);
    cout <<"Insert 50 before 1: " << l << endl;


    cout << "Delete:"  << l.delete_this (l.search(20)) << endl;
    cout << "After deleting: " << l << endl << endl << endl;

    cout <<"Test for struct and -> function: " << endl;
    List <info> list;
    for (int i = 0; i <3; i++) {
        list.insert_head(info(i, i*10));
    }
    cout << list << endl;
    List <info>::Iterator i_it = list.Begin();
    cout << "*i_it: " <<*i_it << endl;
    cout << "*i_it._day: " << (*i_it)._day << endl;
    cout << "*i_it._week: " << (*i_it)._week << endl;
    cout << "i_it -> _day: " << i_it ->_day << endl;
    cout << "i_it -> _week: " << i_it ->_week << endl;

}