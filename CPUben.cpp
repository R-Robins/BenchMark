#include "stdafx.h"
#include <ctime>
#include <iostream>
#include "MatrixOperations.h"
#include "SortingOperation.h"
using namespace std;

int main()
{
    double clockStart, clockEnd, runTime, harmonicMean, doubleScore, integerScore;
    const int TEST_TIME = 10, SCORE_MODIFIER = 4;
    int integerCounter = 0, doubleCounter = 0;
    int endTime;
    

    Matrix matrixOne, matrixTwo;
    matrixOne.initialize();
    matrixTwo.initialize();

    SortingOperation integerSortingOperation;
    

    cout << "========================================================================================\n"
        << "This is a simple benchmark program utilizing double and integer operations.\n"
        << "========================================================================================\n"
        << "Integer operations are checked using merge sort.\n"
        << "Double operations are checked using matrix multiplication.\n"
        << TEST_TIME << " seconds will be allocated to each type of operation.\n\n\n";


    /*=======================
    *Begin Double Test
    =========================*/
    clockStart = clock();
    endTime = clockStart + TEST_TIME * double(CLOCKS_PER_SEC);
    while ( clock() < endTime )
    {
        matrixOne*matrixTwo;
        doubleCounter++;
    }
    clockEnd = clock();
    runTime = (clockEnd - clockStart) / double(CLOCKS_PER_SEC);
    doubleScore = double(doubleCounter) / runTime;

    printf("Double Values:");
    printf("A total of %d operations were performed in %.0lf seconds. \n", doubleCounter, runTime);
    printf("Operations per minute: %.0lf \n", doubleScore*60);
    printf("Operations per second: %.0lf \n\n\n", doubleScore);

    /*=======================
    *Begin Integer Test
    =========================*/
    clockStart = clock();
    endTime = clockStart + TEST_TIME * double(CLOCKS_PER_SEC);
    while (clock() < endTime)
    {
        integerSortingOperation.initializeArray();
        integerSortingOperation.commenceSort();
        integerCounter++;
    }
    clockEnd = clock();
    runTime = (clockEnd - clockStart) / double(CLOCKS_PER_SEC);
    integerScore = double(integerCounter) / runTime;
    
    printf("Integer Values:");
    printf("A total of %d operations were performed in %.0lf seconds. \n", integerCounter, runTime);
    printf("Operations per minute: %.0lf \n", 60 * integerCounter / runTime);
    printf("Operations per second: %.0lf \n\n", integerCounter / runTime);
    

    /*=======================
    *Display Results
    =========================*/
    harmonicMean = 2.0 / (1.0/integerScore + 1.0/doubleScore);
    printf("Harmonic mean: %.0lf \n",harmonicMean );

    printf("===================================================\n");
    printf("Benchmark Score: %.0lf \n", harmonicMean / SCORE_MODIFIER);
    printf("===================================================\n");
    return 0;
}