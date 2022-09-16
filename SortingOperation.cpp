//Merge Sort for Integer Array
#include "stdafx.h"
#include "SortingOperation.h"

/*-------------------------
*  Array Maintenance
*------------------------*/
void SortingOperation::initializeArray()	//Seeds values into array; repeats 0, 1, 2, 3
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sortingArray[i] = counter;
        counter = (counter + 1) % 4;
    }
}

bool SortingOperation::checkArray()		//Verifies that array is sorted
{
    int temp = sortingArray[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (sortingArray[i] < temp) return false;
        temp = sortingArray[i];
    }
    return true;
}

void SortingOperation::commenceSort()	//Calls the sorting operations on the generated array
{
    SortingOperation::sort(sortingArray, 0, SIZE - 1);
}

/*-------------------------
*  Output of Array
*------------------------*/
std::ostream &operator<<(std::ostream &output, SortingOperation &SortingOperation)	//output
{
    output << "Array: \n";
    for (int i = 0; i < SortingOperation::SIZE; i++)
    {
        output << SortingOperation.sortingArray[i] << "  ";
    }
    output << "\n";
    return output;
}

/*-------------------------
*  The Merge Sort
*----------------------*/

void SortingOperation::sort(int arrayToSort[], int lowerBound, int upperBound )  //Primary Sort    ………….                                                                            //Operation
{	
    if (lowerBound < upperBound)
    {
        int midPoint = (upperBound + lowerBound) / 2;	//Declare Midpoint
        sort(arrayToSort, lowerBound, midPoint);		//Recursive Call for Left Side
        sort(arrayToSort, midPoint + 1, upperBound);	//Recursive Call for Right Side

        merge(arrayToSort, lowerBound, midPoint,upperBound );	//Merging function
    }
}

void SortingOperation::merge(int arrayToSort[], int lowerBound,  int midpoint,  int upperBound)		//Merging Operation
{
    int i, j, k;
    const int leftSize = midpoint - lowerBound + 1;  //Size of Left Subarray
    const int rightSize = upperBound - midpoint;	     //Size of Right Subarray

    int *leftArray = new int[leftSize];		//Left Side Subarray
    int *rightArray = new int[rightSize];		//Right Side Subarray

    for (i = 0; i < leftSize; i++) leftArray[i] = arrayToSort[lowerBound + i];	//Transfer Values
    for (j = 0; j < rightSize; j++) rightArray[j] = arrayToSort[midpoint + 1 + j];	//Transfer Values

    i = 0;
    j = 0;
    k = lowerBound;

    while (i < leftSize && j < rightSize)	//This section compares and places values from the   //two subarrays
    {
        if (leftArray[i] <= rightArray[j])
        {
            arrayToSort[k] = leftArray[i]; 	//If leftArray component smaller add it to //the original array
            i++;
        }
        else
        {
            arrayToSort[k] = rightArray[j];	//If rightArray component smaller add it to //original array
            j++;
        }
        k++;
    }

    while (i < leftSize)					   //Adds any remnant values from leftArray
    {
        arrayToSort[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)					  //Adds any remnant values from rightArray
    {
        arrayToSort[k] = rightArray[j];
        j++;
        k++;
    }
    delete leftArray;
    delete rightArray;
}