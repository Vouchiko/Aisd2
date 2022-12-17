#include "matrix.h"
#include <iostream>
#include <random>
#include <complex>

bool double_control(char* xn);
double double_checker();
bool int_control(char* xn);
int int_checker();

template <class T>
Matrix<T>::Matrix() {
    epsilon = 0;
    rows = 0;
    columns = 0;
    matrix = NULL;
}
template <class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}
template <class T>
Matrix<T>::Matrix(int rows, int columns) {
    if (rows > 0)
        this->rows = rows;
    else throw "Invalid value!";
    if (columns > 0)
        this->columns = columns;
    else throw "Invalid value!";

    matrix = new T* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = (T*) new T[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = i + j;
}
template <class T> 
Matrix<T>::Matrix(const Matrix& a)
{
    this->rows = a.rows;
    this->columns = a.columns;
    this->matrix= new T*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = (T*) new T[columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = a.matrix[i][j];
    }
}


template <class T>
int Matrix<T>::GetRows() const {
    return rows;
}

template <class T>
int Matrix<T>::GetCols() const {
    return columns;
}

template <class T>
T Matrix<T>::tr(){
    T result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == j) {
                result += matrix[i][j];
            }
        }
    }
    return result;
}

template <class T>
T& Matrix<T>::operator ()(int i, int j) const {
    if ((i >= 0) && (i < rows) && (j >= 0) && (j < columns))
        return matrix[i][j];
    else throw "Incorrect index values!";
}

template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        return result;
    }
    throw "The dimensions of the matrices do not match! Addition of matrices with different dimensions is unacceptable!";
}

template <class T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        return result;
    }
    throw "The dimensions of the matrices do not match! Subtraction of matrices with different dimensions is unacceptable!";
}

template <class T>
Matrix<T> Matrix<T>::operator / (const T& h) {
    Matrix result(rows, columns);
    if (h == T(0)) {
        std::cout << "invalid syntax, division by zero is not possible";
    }
    else {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] / h;
    }
    return result;
}

template <class T>
void Matrix<T>::EnterMatrix() {
    std::cout << "Enter the dimension of the matrix:" << endl;
    std::cout << "Number of rows: ";
    int newRows = int_checker();
    std::cout << "Number of columns: ";
    int newColumns = int_checker();

    Matrix newMatrix(newRows, newColumns);
    for (int i = 0; i < newRows; i++)
        for (int j = 0; j < newColumns; j++) {
            std::cout << "Cell (" << i << ", " << j << ") = ";
            std::cin >> newMatrix.matrix[i][j];
        }
    *this = newMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator * (const T& h){
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] * h;
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator * (const Matrix<T>& rhs) {
    if (columns == rhs.rows) {
        Matrix result(rows, rhs.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                result.matrix[i][j] = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                for (int k = 0; k < columns; k++)
                    result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
        return result;
    }
    throw "Matrices cannot be multiplied! Invalid dimension!";
}

template <class T>
bool Matrix<T>::operator == (const Matrix& rhs) {
    bool result = true;
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (abs(matrix[i][j] - rhs.matrix[i][j]) > epsilon) {
                    result = false;
                }
    }
    else {
        result = false;
    }
    return result;
}

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& a) {
    this->~Matrix();
    this->rows = a.rows;
    this->columns = a.columns;
    this->matrix = new T* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new T[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = a.matrix[i][j];
    return *this;
}
template <class T>
Matrix<T> Matrix<T>::Solution_of_the_equation(const Matrix& Mat) {
    T det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) -
        matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
        matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    T invdet = (T(1) / det);

    Matrix matrix2(3, 3);
    matrix2(0, 0) = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * invdet;
    matrix2(0, 1) = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invdet;
    matrix2(0, 2) = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invdet;
    matrix2(1, 0) = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invdet;
    matrix2(1, 2) = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) * invdet;
    matrix2(1, 1) = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invdet;
    matrix2(2, 0) = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) * invdet;
    matrix2(2, 1) = (matrix[2][0] * matrix[0][1] - matrix[0][0] * matrix[2][1]) * invdet;
    matrix2(2, 2) = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * invdet;

    Matrix matrixResult = matrix2 * Mat;
    return matrixResult;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<complex<float>>;
template class Matrix<complex<double>>;