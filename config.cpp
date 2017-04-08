
#include "config.hpp"


void read_config( rdsSystem *sysParams )
{
    std::string str_elem;
	bool insideBlock = false;

	// 0) Read configuration dictionary
    std::basic_ifstream<char> config_file; 	
	config_file.open( (*sysParams).paramFile.c_str() );
	while ( config_file.fail() )
    {
		std::cout << std::endl << (*sysParams).paramFile.c_str() << "not found!"
			<< std::endl << "Please enter a configuration file:"
			<< std::endl;
		std::cin >> (*sysParams).paramFile;
		config_file.open( (*sysParams).paramFile.c_str() );
		std::cout << (*sysParams).paramFile.c_str() << std::endl;
	}
		  
	std::cout << "Read configuration from file \""  
		<< (*sysParams).paramFile.c_str() << "\""
		<< std::endl << std::endl;
	
    while(config_file >> str_elem){
		if( str_elem == "{")
			insideBlock = true;
		else if( str_elem == "}" )
			insideBlock = false;
			
		// RDS spectrometer
		if( str_elem == "Bx_rot" && insideBlock)
			config_file >> (*sysParams).Bx_rot;
		if( str_elem == "By_rot" && insideBlock)
			config_file >> (*sysParams).By_rot;
			
		if( str_elem == "Bx_off" && insideBlock)
			config_file >> (*sysParams).Bx_off;
		if( str_elem == "By_off" && insideBlock)
			config_file >> (*sysParams).By_off;
		if( str_elem == "Bz_off" && insideBlock)
			config_file >> (*sysParams).Bz_off;
		
		if( str_elem == "om_0" && insideBlock)
			config_file >> (*sysParams).om_0;
		if( str_elem == "om_x" && insideBlock)
			config_file >> (*sysParams).om_x;
		if( str_elem == "om_y" && insideBlock)
			config_file >> (*sysParams).om_y;
		
		// Particle System
		if( str_elem == "temperature" && insideBlock)
			config_file >> (*sysParams).temperature;
		if( str_elem == "hydDiameter" && insideBlock)
			config_file >> (*sysParams).hydDiameter;
		if( str_elem == "viscosity" && insideBlock)
			config_file >> (*sysParams).viscosity;
		
		// Numeric
		if( str_elem == "StartTime" && insideBlock)
			config_file >> (*sysParams).StartTime;
		if( str_elem == "EndTime" && insideBlock)
			config_file >> (*sysParams).EndTime;
		if( str_elem == "DeltaTime" && insideBlock)
			config_file >> (*sysParams).DeltaTime;
			
	}
	config_file.close();
}


void test_config( rdsSystem *rdsParams )
{
	std::cout << std::endl << "Parameters: " << std::endl <<std::endl;

	// RDS spectrometer
	std::cout << std::endl << "Bx_rot: \t" << (*rdsParams).Bx_rot;
	std::cout << std::endl << "By_rot: \t" << (*rdsParams).By_rot;
	std::cout << std::endl << std::endl;
	
	std::cout << std::endl << "Bx_off: \t" << (*rdsParams).Bx_off;
	std::cout << std::endl << "By_off: \t" << (*rdsParams).By_off;
	std::cout << std::endl << "Bz_off: \t" << (*rdsParams).Bz_off;
	std::cout << std::endl << std::endl;

	std::cout << std::endl << "om_0: \t" << (*rdsParams).om_0;
	std::cout << std::endl << "om_x: \t" << (*rdsParams).om_x;
	std::cout << std::endl << "om_y: \t" << (*rdsParams).om_y;
	std::cout << std::endl << std::endl;

	// Particle System
	std::cout << std::endl << "temperature: \t" << (*rdsParams).temperature;
	std::cout << std::endl << "hydDiameter: \t" << (*rdsParams).hydDiameter;
	std::cout << std::endl << "viscosity: \t" << (*rdsParams).viscosity;
	std::cout << std::endl << std::endl;

	// Numeric
	std::cout << std::endl << "StartTime: \t" << (*rdsParams).StartTime;
	std::cout << std::endl << "EndTime: \t" << (*rdsParams).EndTime;
	std::cout << std::endl << "DeltaTime: \t" << (*rdsParams).DeltaTime;
	std::cout << std::endl << std::endl;

}
