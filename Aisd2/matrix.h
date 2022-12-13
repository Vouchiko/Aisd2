#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;

template <class T>

class Matrix {
private:
	int rows, columns;
	T** matrix;
	T** matrix2;
public:
	double epsilon;
	Matrix();
	Matrix(int rows, int columns);
	//Matrix(const Matrix& Matrix);
	//Matrix(int rows, int columns, const T&value);
	void EnterMatrix();
	T& operator () (int m, int n) const;

	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const T& h);
	Matrix operator / (const T& h);
	bool operator == (const Matrix& rhs);
	friend Matrix operator / (const T& scalar, Matrix& rhs);
	friend Matrix operator * (const T& scalar, Matrix& rhs);
	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix);
	int GetRows() const;
	int GetCols() const;
	T tr();
	Matrix<T> Solution_of_the_equation(const Matrix& vector);

};

