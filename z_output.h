//
// Created by tangb on 5/3/2020.
//

#ifndef ITERATOR_Z_OUTPUT_H
#define ITERATOR_Z_OUTPUT_H
//---------------------------------------------------------------------
// Test for functions
//---------------------------------------------------------------------

//-------------- RESULTS --------------------
/*
 * Test for some functions:
5|4|3|2|1|0|
Copy constructor: 5|4|3|2|1|0|
Assignment operator: 5|4|3|2|1|0|
Insert 20 after 3: 5|4|3|20|2|1|0|
Insert 50 before 1: 5|4|3|20|2|50|1|0|
Delete:20
After deleting: 5|4|3|2|50|1|0|


Test for struct and -> function:
[2, 20]|[1, 10]|[0, 0]|
*i_it: [2, 20]
*i_it._day: 2
*i_it._week: 20
i_it -> _day: 2
i_it -> _week: 20
*/

//---------------------------------------------------------------------
// Test for navigation
//---------------------------------------------------------------------

//-------------- RESULTS --------------------

/*..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{43}->[9]->[2]->[74]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        n
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->{9}->[2]->[74]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        n
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->[9]->{2}->[74]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        e
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->[9]->[2]->[74]->{8}->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        h
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{43}->[9]->[2]->[74]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        s
??
74
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->[9]->[2]->{74}->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        d
74
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{43}->[9]->[2]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        a
??
22
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->{22}->[9]->[2]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        b
??
10
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->[10]->[22]->[9]->[2]->[8]->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        e
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[43]->[10]->[22]->[9]->[2]->{8}->|||
Menu: [A]fter [B]efore  [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd  e[X]it
        X


*/
#endif //ITERATOR_Z_OUTPUT_H
