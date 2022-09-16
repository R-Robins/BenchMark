#pragma once
#ifndef SORTING_OPERATION_H
#define SORTING_OPERATION_H
#include <iostream>
#pragma once

class SortingOperation
{
    friend std::ostream &operator<<(std::ostream&, SortingOperation &);

private:
    static const int SIZE = 6000;	//Set size to do around same ops/sec as matrix multiplication
    int sortingArray[SIZE];		//Allocating memory for array that will be sorted

public:
    void initializeArray();		//Initializes array with values
    void commenceSort();		//Begins the sort operation with the initialized array
    bool checkArray();		//Verifies array was sorted correctly
    static void sort( int[], int lowerBound, int upperBound );		//Main sorting method
    static void merge(int arrayToSort[], int lowerBound, int midpoint, int upperBound);  //Merging                 .                                                                        //method within sort method
};

#endif