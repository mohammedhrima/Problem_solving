/*
N people with ID 1,2,....N
Q events:
    1  : Teller calls the person with samllest ID / for the first time
    2 x: Person with ID = x comes to teller for 1st time / has already been called at least once
                                                           will come only one time
    3  : Teller calls the person with smallest ID again / has not come
                                                        / event repeated at least one time
    print ID of peoples with events = 3 / Teller called person with smallest ID
1 <= N 
2 <= Q
*/

