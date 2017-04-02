
#include "config.hpp"


void read_config( rdsSystem *sysParams )
{
    std::string str_elem;
    float param;
	bool insideBlock = false;

	// 0) Read configuration dictionary
    std::basic_ifstream<char> file; 	
	file.open( (*sysParams).paramFile.c_str() );
	if ( file.fail() ) // stop simulation without configuration file
	{
		std::cout << "Error opening parameter file!"
			<< "(file name: \"" << (*sysParams).paramFile.c_str()
			<< "\")" << std::endl << "Simulation aborted"
			<< std::endl;
		file.clear();
		throw; 
	}	
	else
	{
		std::cout << "Read configuration from file \""  
			<< (*sysParams).paramFile.c_str() << "\""
			<< std::endl << std::endl;
	}
    while(file >> str_elem){
		if( str_elem == "{")
			insideBlock = true;
		else if( str_elem == "}" )
			insideBlock = false;
		if( str_elem == "B_rot" && insideBlock){
			file >> param;
			std::cout << str_elem << '\t' << param << "\tRED" << std::endl;
			(*sysParams).Bx_rot = param;
			(*sysParams).By_rot = param;
		}
		if( str_elem == "B_off" && insideBlock){
			file >> param;
			std::cout << str_elem << '\t' << param << "\tBLUE" << std::endl;
		}
		if( str_elem == "OM_y" && insideBlock){
			file >> param;
			std::cout << str_elem << '\t' << param << "\tGREEN" << std::endl;
		}
	}
	file.close();
}


void test_config( rdsSystem *rdsParams )
{
	std::string str = "string-test";

	std::cout << std::endl << "config.hpp is executed..." << '\t' << (*rdsParams).Bx_rot << std::endl;
	std::cout << std::endl << str << std::endl;
}
