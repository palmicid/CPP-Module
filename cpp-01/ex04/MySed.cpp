#include "MySed.hpp"
#include <iostream>
#include <fstream>
#include <string>

MySed::MySed( std::string fname, std::string s1, std::string s2 ) : _fname(fname), _s1(s1), _s2(s2)
{
}

MySed::~MySed()
{	
}

void	MySed::myReplace()
{
	// open filein and file out 
	std::string	outFname = this->_fname + ".replace";
	std::ifstream	fileIn(this->_fname);
	fileIn.open( this->_fname, std::fstream::in );
	if (!fileIn.is_open())
	{
		std::cout << "FAIL to open " << this->_fname << std::endl;
		return ;
	}
	std::ofstream	fileOut(outFname, std::ofstream::trunc);
	if (!fileOut.is_open())
	{
		std::cout << "FAIL to open " << outFname << std::endl;
		fileIn.close();
		return ;
	}
	
	// get file content
	std::string line;
	while (std::getline(fileIn, line)) {
		// Process each line (string) from the file
		std::cout << line << std::endl;
	}

	// std::string	tmpStr;
	
	// while (std::getline(fileIn, tmpStr))
	// {
	// 	// find and replace
	// 	size_t	pos = 0;
	// 	while ((pos = tmpStr.find(this->_s1, pos)) != std::string::npos)
	// 	{
	// 		tmpStr.erase(pos, this->_s1.length());
	// 		tmpStr.insert(pos, this->_s2);
	// 		pos += this->_s2.length();
	// 	}
	// 	fileOut << tmpStr;
	// }
}
