#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  Matrix my(2, 2);
  my.at(0, 0) = 5;
  my.at(0, 1) = 4;
  my.at(1, 0) = 3;
  my.at(1, 1) = 2;
  my.printMatrix();
  Matrix lol(2, 2);
  lol.at(0, 0) = 1;
  lol.at(0, 1) = 1;
  lol.at(1, 0)= 1;
  lol.at(1, 1) = 1;
  Matrix poo = my * lol;
  poo.printMatrix();
  return 0;
}
