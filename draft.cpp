//vi draft.cpp && clear && g++ draft.cpp -std=c++0x -larmadillo && ./a.out

#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;


main(){
mat A = randu<mat>(5,5);

mat B = A.col(1);

vec x = linspace<vec>(0, 3, 10);
vec v(5);
v = {1.0,2.0,3.0,4.0,5.0};

A.col(3) = sin(v) ;

cout << endl << M_PI << endl;
cout << endl << A << endl << endl;
cout << endl << B << endl << endl;
cout << endl << sin(x) << endl << endl;
}
