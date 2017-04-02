/*--------------------------------------------------------------------------------

 libraries: lapack, blas and armadillo


 1) initialize -> 2) simulate -> 3) store results -> 4) visualize results

vi compile-and-run:
:wall:!clear; make && ./openRDS
--------------------------------------------------------------------------------*/


#include <iostream>

#include <armadillo>

#include "rds.hpp"
#include "config.hpp"

using namespace std;
using namespace arma;


int main(int argc, char* argv[])
{
	rdsSystem rdsSys_1;
	rdsSys_1.paramFile = "rdsSystemParams";
	read_config( &rdsSys_1 );
	test_config( &rdsSys_1 );
	
	cout << endl << endl << dummy_fun2(5,6) << endl << endl;

    mat X(4,5,fill::ones);
    cout << "X has " << X.n_cols << " columns" << endl;
    
    mat B; B.randu(4,5);
    cout << endl << B << endl;
    cout << endl << pinv(B) << endl;
    cout << endl << B * pinv(B) << endl;
    
    
}


