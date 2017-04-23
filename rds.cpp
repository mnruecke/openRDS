/*
	RDS simulation -
*/	

/* SDGL implementation:

1.) Euler forward
    dm/dt = m dn/dt = 1/gamma [ (B x m + W) x m ]

					= 1/gamma (B x m) x m	+ 	1/gamma W x m
   
    m(i+1) = m(i) + dm(i)

    {Bx, By, Bz}(i) = {Bx_rot * sin( (om_0 + om_x) * i) + Bx_off,
					   By_rot * cos( (om_0 + om_y) * i) + By_off,
										Bz_off}
*/


#include "rds.hpp"



void core_draft1( rdsSystem *sysParams )
{
	// System parameters:
	int timePoints = 1000;
	float brownian = 0.01;

	float Bx_rot = (*sysParams).Bx_rot;
	float By_rot = (*sysParams).By_rot;
	float Bx_off = (*sysParams).Bx_off;
	float By_off = (*sysParams).By_off;
	float Bz_off = (*sysParams).Bz_off;
	float om_0 = (*sysParams).om_0;
	float om_x = (*sysParams).om_x;
	float om_y = (*sysParams).om_y;
	float phi_x = (*sysParams).phi_x * M_PI;
	float phi_y = (*sysParams).phi_y * M_PI;

//	float gamma = 3;

	// Random forces
	arma::mat W;
    W.randn( DIMSYS, timePoints);

	// External magnetic field
	arma::mat B( DIMSYS, timePoints);
	arma::vec b_i; 
	for( int i=0; i<timePoints; i++ )
	{
		b_i	<< Bx_rot * sin( (om_0 + om_x) * i + phi_x) + Bx_off
			<< By_rot * sin( (om_0 + om_y) * i + phi_y) + By_off
			<< Bz_off
		<< arma::endr;
		B.col(i) = b_i;  
	}

	// Magnetic moment
    arma::mat M( DIMSYS, timePoints, arma::fill::zeros);
	arma::vec m_0(3); m_0 << 1 << 0 << 0 << arma::endr;
	M.col(0) = m_0;

	// Time evolution ( magnetic "point-charge" moving on spherical surface)
	for( int i=0; i<timePoints-1; i++)
	{
		M.col(i+1) = M.col(i)\
				 + cross( M.col(i),\
			 		(brownian * W.col(i)\
						 + cross( B.col(i), M.col(i) ) ));
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


	
