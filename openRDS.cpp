/*--------------------------------------------------------------------------------

 libraries: lapack, blas and armadillo


 1) initialize -> 2) simulate -> 3) store results -> 4) visualize results

vi compile-and-run:
:wall:!clear; make && ./openRDS
--------------------------------------------------------------------------------*/


#include <iostream>

#include <armadillo>

#include "rds.hpp"

using namespace std;
using namespace arma;


int main(int argc, char* argv[])
{
	rdsSystem rdsSys_1;
	rdsSys_1.paramFile = "rdsSystemParams";
	read_config( &rdsSys_1 );
	test_config( &rdsSys_1 );

    core_draft1( &rdsSys_1 );

    
    
}


