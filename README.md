LinkedList
=======================

LinkedList recursive and non recursive implementation in c.

##Functionalities

Function Name | Definition
------------ | -------------
int member(int n, cell *p): |It takes two arguments: a number n and a pointer p to a list and it returns 1 if the number is found in the list, 0 otherwise.

(cell *) delete(int n, cell *p): |It takes two arguments: a number n and a pointer p to a list. It returns a list that is obtained by deleting the number n from the list p. If the number is not found, then p is returned unchanged.

int last(cell *p): |It takes a pointer p to a list as an argument and returns the last element in the list (if the list is empty, it return -1).int last(cell *p): |It takes a pointer p to a list as an argument and returns the last element in the list (if the list is empty, it return -1).

(cell *) reverse(cell *p): |It takes as an argument a pointer p to a list and returns a pointer to a list that contains all the elements of the list p in reverse order.void display(cell *p): |It takes a pointer p to a list as an argument and prints the list as an ML list on the standard output. Thus, the list 10->20->30->nil will be displayed as [10,20,30].

##Project Contributor

* Dinesh Appavoo ([@DineshAppavoo](https://twitter.com/DineshAppavoo))
