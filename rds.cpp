/*
	RDS simulation -
*/	

/* SDGL implementation:

1.) Euler forward
    dm/dt = m dn/dt = 1/gamma [ (B x m + w) x m ]
   
    m(i+1) = m(i) + dm(i)


*/


#include "rds.hpp"

int timePoints = 100;
int dimM = 3;
float brownian = 0.5;

void core_draft1(double num_a,double num_b)
{
	// Random forces
	arma::mat W;
    W.randn( dimM, timePoints);

	// External magnetic field
	arma::mat B( dimM, timePoints);

	// Magnetic moment
    arma::mat M( dimM, timePoints, arma::fill::zeros);
    arma::mat aa(3,1,arma::fill::eye);
	M.col(0) = aa;

	// Time evolution ( magnetic "point-charge" moving on spherical surface)
	for( int i=0; i<timePoints-1; i++)
	{
		M.col(i+1) = M.col(i) + cross( M.col(i), brownian * W.col(i));
		M.col(i+1) = M.col(i+1) / sqrt(sum(square(M.col(i+1))));
	}

/*
	std::cout << std::endl << W.col(1) << std::endl
			  << square(W.col(1)) << std::endl 
			  << 1.0/sqrt(sum(square(W.col(1)))) << std::endl << std::endl;
*/


	// Store results in *.dat file
	std::ofstream resultFile;
	resultFile.open( "results.dat");
	resultFile << M;
	resultFile.close();

}


	
