#pragma once
#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H
#include <iostream>
static const int SIZE = 100;

class Matrix
{
	friend std::ostream &operator<<(std::ostream&, Matrix &);

private:
	double doubleMatrix[SIZE][SIZE];  //Matrix will be the square and the size defined above      

public:
	Matrix operator-(Matrix&);        //Subtraction
	Matrix operator+(Matrix&);        //Addition
	Matrix operator*(Matrix&);        //Multiplication

	void zero();			       //Zeroes out a matrix
	void initialize();                //Sets matrix to default values
	Matrix();			       //Only Need Default Constructor					  
};

#endif //MATRIX_MULTIPLICATION_MATRIX_H
