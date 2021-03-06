#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//constructor
// in my code, r represents the number of rows and c for the
// number of columns
Matrix::Matrix(uint rows, uint cols) {
  r = rows;
  c = cols;
  double** rPointer = new double*[rows];
  head = rPointer;
  for (uint i = 0; i < rows; i++) {
    double* temp = new double[cols];
    rPointer[i] = temp;
    for (uint j = 0; j < cols; j++) {
      temp[j] = 0;
    } //for
  } //for
} // constructor

//constructor for array
Matrix::Matrix(double** values, int w, int h) {
  head = values;
  r = w;
  c = h;
}//constructor

// constructor
Matrix::Matrix(const Matrix & m) {
  r = m.numRows();
  c = m.numCols();
  double** rPointer = new double*[r];
  head = rPointer;
  for (uint i = 0; i < r; i++) {
    double* temp = new double[c];
    rPointer[i] = temp;
    for (uint j = 0; j < c; j++) {
      temp[j] = m.at(i, j);
    } //for                                                                                                                                                                                              
  } //for              
} //constructor

//destructor
Matrix::~Matrix() {
  for (uint i = 0; i < r; i++) {
    delete[] head[i];
  }
  delete[] head;
} //~Matrix

// the add function adds a user specified double to each value
// in the matrix.
Matrix Matrix::add(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for ( uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) + s;
    } //for
  } //for
  return m;
} //add

// this add function adds two matrices together
Matrix Matrix::add(const Matrix & m) const {
  Matrix m2(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m2.at(i, j) = m2.at(i, j) + m.at(i, j);
    } //for
  } //for
  return m2;
} // add

// the subtract function subtracts a user specified double from  each
// value in the matrix.
Matrix Matrix::subtract(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) - s;
    } //for
  } //for
  return m;
} //subtract

// this subtract functions subtracts one matrix from the other
Matrix Matrix::subtract(const Matrix & m) const{
  Matrix m2(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m2.at(i, j) = m2.at(i, j) - m.at(i, j);
    } //for
  } //for
  return m2;
} //subtract

// this multiplication function multiplies a user specified
// double to each value within the matrix 
Matrix Matrix::multiply(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) * s;
    } //for
  } //for
  return m;
} //multiply

//multiplies two matrices together
Matrix Matrix::multiply(const Matrix & m) const {
  Matrix m2(numRows(), m.numCols());
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      for (uint p = 0; p < c; p++) {
	m2.at(i, j) += at(i, p) * (m.at(p, j));
      } //for
    } //for
  } //for
  return m2;
} //multiply

//divides each number within the matrix with a user specified double
Matrix Matrix::divide(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) / s;
    } //for
  } //for
  return m;
} //divide

Matrix Matrix::t() const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(j, i) = at(i, j); 
    } //rows
  } //for
  return m;
} 

// returns the number of rows
const uint Matrix::numRows() const {
  return r;
} //numRows

// returns the number of columns
const uint Matrix::numCols() const {
  return c;
} //numCols

//returns the value at specified index in Matrix
double & Matrix::at(uint row, uint col) {
  double & temp = head[row][col];
  return temp;
} //at

//return the value at specified index in Matrix
const double & Matrix::at(uint row, uint col) const {
  double & temp = head[row][col];
  return temp;
} //at

//this function overrides the additon operator
//in certain instances
Matrix Matrix::operator+(double num) const{
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) + num;
    } //for
  } //for
  return m;
} //operator+

//this function overrides the addition operator in
//certain instances
Matrix Matrix::operator+(const Matrix& mat1) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) + mat1.at(i, j);
    } //for
  } //for
  return m;
} //operator+

//this function overrides the subtration
//operatir in certain instances
Matrix Matrix::operator-(double num) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) - num;
    } //for                                                                                                                                   
  } //for                                                                                                                                     
  return m;
} //operator- 

//this function overries the subtraction operator in
//certain instances
Matrix Matrix::operator-(const Matrix& mat1) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) - mat1.at(i, j);
    } //for                                                                                                                              
  } //for                                                                                                                                   
  return m;
} //operator-

//this function overrides the multiplication
//operator in certain instances
Matrix Matrix::operator*(double num) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) * num;
    } //for                                                                                                                                   
  } //for                                                                                                                                     
  return m;
} //operator*

//this function overrides the multiplcation
//operator in certain instances
Matrix Matrix::operator*(const Matrix& mat1) const {
  Matrix m(numRows(), mat1.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < mat1.numCols(); j++) {
      for (uint p = 0; p < mat1.numCols(); p++) {
        m.at(i, j) += at(i, p) * (mat1.at(p, j));
      } //for
    } //for
  } //for                                                                                                                                     
  return m;
} //operator*


//this function overrides the division operator
//in certain instances
Matrix Matrix::operator/(double num) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j) / num;
    } //for
  } //for
  return m;
} //operator/

//this function overrides the () operator in ceratin
//instances
double Matrix::operator()(uint row, uint col) const {
  Matrix m(*this);
  return m.at(row, col);
} //operator()

//this function overrides the assignment operator in
//certain instances
Matrix Matrix::operator=(const Matrix& mat1) const {
  Matrix m(*this);
  Matrix temp(*this);
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = temp.at(i, j);
    } //for
  } //for
  return m;
} //operator=

//this function overrides the output stream operator in ceratain
// instances
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  os << "";
  for (uint i = 0; i < m.numRows(); i++) {
    os << "[ ";
    for (uint j = 0; j < m.numCols(); j++) {
      os << m.at(i, j) << ", ";
    } //for
    os << m.at(i, m.numCols() - 1) << " ]" << "/n";
  } //for
  return os;
} //operator<<

//this function overrides the addition opreator in certain instances
 Matrix operator+(double num, const Matrix& mat1) {
  Matrix m(mat1.numRows(), mat1.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = num + mat1.at(i, j);
    } //for
  } //for
  return m;
} //operator+

//this function overrides the subtraction operator in certain instances
Matrix operator-(double num, const Matrix& mat1) {
  Matrix m(mat1.numRows(), mat1.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = num - mat1.at(i, j);
    } //for
  } //for
  return m;
} //operator+

//this function overrides the multiplication operator in certain
// instances
Matrix operator*(double num, const Matrix& mat1) {
  Matrix m(mat1.numRows(), mat1.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = num * mat1.at(i, j);
    } //for                                                                                                                                              
  } //for                                                                                                                                               
  return m;
} //operator+

//this function overrides the division operator in certain instances
Matrix operator/(double num, const Matrix& mat1) {
  Matrix m(mat1.numRows(), mat1.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      m.at(i, j) = num / mat1.at(i, j);
    } //for
  } //for                                                                                                                                                         
  return m;
} //operator+      

//this function is prints out my matrice in a format
// so that other functions may be tested
void Matrix::printMatrix () {
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      cout <<at(i, j) << " ";
    } //for
    cout << endl;
  } //for
} //printMatrix
