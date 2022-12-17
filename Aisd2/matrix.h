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
public:
	double epsilon;
	Matrix();
	Matrix(int rows, int columns);
	~Matrix();
	Matrix(const Matrix& obj);
	void EnterMatrix();
	T& operator () (int m, int n) const;

	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const T& h);
	Matrix operator / (const T& h);
	bool operator == (const Matrix& rhs);
	friend Matrix operator * (const T& h, Matrix& matrix)
	{
		Matrix result(matrix.GetRows(), matrix.GetCols());
		result = matrix * h;
		return result;
	}
	friend std::ostream& operator << (std::ostream& s, const Matrix<T>& matrix)
	{
		for (int i = 0; i < matrix.rows; i++) {
			for (int j = 0; j < matrix.columns; j++)
				s << matrix.matrix[i][j] << " ";
			s << "\n";
		}
		return s;
	}
	Matrix& operator = (const Matrix& a);
	int GetRows() const;
	int GetCols() const;
	T tr();
	Matrix<T> Solution_of_the_equation(const Matrix& vector);

};



