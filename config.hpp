#include <iostream>
#include <fstream>

struct rdsSystem
{
	// Simulation parameter file
	std::string paramFile;
	
	// RDS spectrometer
	float Bx_rot;
	float By_rot;
	
	float Bx_off;
	float By_off;
	float Bz_off;

	float om_0;
	float om_x;
	float om_y;

	float phi_x;
	float phi_y;

	// Particle System
	float temperature;
	float hydDiameter;
	float viscosity;

	// Numeric
	float StartTime;
	float EndTime;
	float DeltaTime;
};


void read_config( rdsSystem * );
void test_config( rdsSystem * );
