#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{	
}

BitcoinExchange::BitcoinExchange(std::string const &fname)
{
	// cx openfile
	std::ifstream	fin;

	// init database
	if (init_database())
		throw DatabaseFailException();
	if (cxFile(fname))
		throw OpenFileException();
	if (openFile(fin, fname))
		throw OpenFileException();
	readFile(fin);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	*this = other;
}


BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::DatabaseFailException::what() const throw() { return "Failed to add database"; }
const char* BitcoinExchange::OpenFileException::what() const throw() { return "Cannot Open File"; }


//	helper zone ======================================================================================

int		BitcoinExchange::init_database()
{
	std::ifstream	dbin;

	dbin.open("another.csv", std::ifstream::in);
	// dbin.open("data.csv", std::ifstream::in);
	if (!dbin.is_open()) {
		return 1;
	}

	// add data to multimap
	std::string		line;

	//for skip first line
	std::getline(dbin, line);

	while (std::getline(dbin, line)) {
		toAddData(line);
	}

	// print test 
	std::multimap<std::string, float>::iterator	st = _database.begin();
	std::multimap<std::string, float>::iterator	ed = _database.end();
	while (st != ed) {
		std::cout << "key = " << st->first << " value = " << st->second << std::endl;
		st++;
	}


	return 0;
}


int		BitcoinExchange::openFile(std::ifstream &in, std::string const &name)
{	
	in.open(name.c_str(), std::ifstream::in);
	if (!in.is_open()) {
		return 1;
	}
	return 0;
}

void	BitcoinExchange::toAddData(std::string const &line)
{
	std::string		fwd, aft;
	float			convert;
	std::string::size_type	n = line.find(',');

	if (n != line.rfind(','))
		std::cout << "wrongformat" << std::endl;
	fwd = line.substr(0, n);
	aft = line.substr(n + 1);
	convert = atof(aft.c_str());
	_database.insert(std::pair<std::string, float>(fwd, convert));


}

int		BitcoinExchange::cxFile(std::string const &fname)
{
	std::string::size_type	n;
	n = fname.rfind(".txt");
	if (n == std::string::npos || (fname.length() - n != 4))
		return 1;
	return 0;
}

int		BitcoinExchange::readFile(std::ifstream &fin)
{
	std::string		line;

	(void)fin;
	// while (std::getline(fin, line)) {
	// 	toAddData(line, '|');
	// }
	


	return 0;
}
