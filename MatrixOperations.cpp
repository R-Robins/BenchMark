//This is responsible for matrix operations

#include "stdafx.h"
#include "MatrixOperations.h"


/*-------------------------
*  Constructors
*----------------------*/
Matrix::Matrix()
{ }


/*-----------------
*  Operations
*----------------*/
void Matrix::zero()		//zeroes out a matrix
{
for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        this->doubleMatrix[i][j] = 0;
    }
}
}

void Matrix::initialize()	//initializes matrix with diagonal values as 2.00001 
                            //and everything else as 1.00001
{
for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        (i == j) ? this->doubleMatrix[i][j] = 2.00001 : this->doubleMatrix[i][j] = 1.00001;
    }
}
}


Matrix Matrix::operator+(Matrix& otherMatrix)	//addition operation
{
Matrix resultingMatrix = Matrix();
resultingMatrix.zero();

for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        resultingMatrix.doubleMatrix[i][j]=this->doubleMatrix[i][j] +otherMatrix.doubleMatrix[i][j];
    }
}
return resultingMatrix;
}
    

Matrix Matrix::operator-(Matrix& otherMatrix)	//subtraction operation
{
Matrix resultingMatrix = Matrix();
resultingMatrix.zero();

for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        resultingMatrix.doubleMatrix[i][j] = this->doubleMatrix[i][j] - otherMatrix.doubleMatrix[i][j];
    }
}
return resultingMatrix;
}


Matrix Matrix::operator*(Matrix& otherMatrix)	//multiplication operation
{
Matrix resultingMatrix = Matrix();
for (int i = 0; i < SIZE; ++i)
{
    for (int j = 0; j < SIZE; ++j)
  {
        resultingMatrix.doubleMatrix[i][j] = 0;
        for (int k = 0; k < SIZE; ++k)
        {
            resultingMatrix.doubleMatrix[i][j] += this->doubleMatrix[i][k] * otherMatrix.doubleMatrix[k][j];
        }
    }
}
return resultingMatrix;
}


std::ostream &operator<<(std::ostream &output, Matrix &matrix)	//output
{
for (int rowIndex = 0; rowIndex < SIZE; rowIndex++)
{
    output << "\n";
    for (int colIndex = 0; colIndex < SIZE; colIndex++)
    {
        output << matrix.doubleMatrix[rowIndex][colIndex] << "\t";
    }
}
output << "\n";
return output;
}
