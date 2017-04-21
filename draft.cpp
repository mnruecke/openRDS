//vi draft.cpp && clear && g++ draft.cpp -std=c++0x -larmadillo && ./a.out

#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;


main(){
mat A = randu<mat>(5,5);

mat B = A.col(1);


vec v(5);
v << 1 << 2 << 3 << 33 << 333 << endr;  

A.col(3) =  v;

cout << endl << A << endl << endl;
cout << endl << B << endl << endl;
cout << endl << A*A << endl << endl;
}
