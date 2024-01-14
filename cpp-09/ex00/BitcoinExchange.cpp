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

static time_t	convertDate(std::string const &);

int		BitcoinExchange::init_database()
{
	std::string		dbname = "data.csv";
	std::ifstream	dbin;

	if (cxFile(dbname))
		return 1;
	dbin.open(dbname.c_str(), std::ifstream::in);
	if (!dbin.is_open()) {
		return 1;
	}

	// add data to map
	std::string		line;

	//for skip first line
	std::getline(dbin, line);

	while (std::getline(dbin, line)) {
		toAddData(line);
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
	n = fname.rfind(".csv");
	if (n == std::string::npos || (fname.length() - n != 4))
		return 1;
	return 0;
}

void	BitcoinExchange::readFile(std::ifstream &fin)
{
	std::string		line;
	time_t			date;

	// skip first line
	std::getline(fin, line);
	while (std::getline(fin, line)) {
		// cx formal
		float	coin;
		std::string		fwd, aft;
		// split 2 part and cx data inside
		if (cxFormatAndSplit(line,fwd,aft, date, coin))
			continue;
		// find pair to cx value 
		findRate(date,coin, fwd);
	}
}

static time_t	convertDate(std::string const &str)
{
	std::string		sub[3];
	// //	convert str to int
	sub[0] = str.substr(0, 4);
	sub[1] = str.substr(5, 2);
	sub[2] = str.substr(8, 2);

	tm	d = {};

	d.tm_year = std::atoi(sub[0].c_str());
	d.tm_mon = std::atoi(sub[1].c_str());
	d.tm_mday = std::atoi(sub[2].c_str());
	
	time_t time1 = mktime(&d);

	return time1;	
}


static int	fwd_ok(std::string &fwd, time_t &date)
{
	// cx lenght 
	if (fwd.length() != 10) {
		std::cout << "Error: Something not right in date format => " << fwd << std::endl;
		return 1;
	}
	// cx format
	for (size_t i = 0; i < fwd.length(); i++) {
		if (i == 4 || i == 7) {
			if (fwd[i] != '-') {
				return 1;
			}
		}
		else {
			if (!isdigit(fwd[i])) {
				return 1;
			}
		}
	}
	// cx date
	date = convertDate(fwd);
	if (date == -1) {
		return 1; 
	}
	return 0;
}

// print error and return
int		aft_ok(std::string &str, float &coin)
{
	// -
	if (str[0] != '-' && !isdigit(str[0])) {
		std::cout << "Error: bad input not number => " << str << std::endl;
		return 1;
	}
	// digit
	int dot = 0;
	for (size_t n = 1; n < str.length(); n++) {
		if (!isdigit(str[n]) && str[n] != '.') {
			std::cout << "Error: bad input not number => " << str << std::endl;
			return 1;
		}
		if (str[n] == '.')
			dot++;
		if (dot > 1) {
			std::cout << "Error: bad input => " << str << std::endl;
			return 1;
		}
	}
	// convert
	coin = std::atof(str.c_str());

	// 0 - 1000
	if (coin < 0) {
		std::cout << "Error: not a positive number" << std::endl; 
		return 1;
	}
	if (coin > 1000) {
		std::cout << "Error: number too large" << std::endl;
		return 1;
	}

	return 0;
}


int		BitcoinExchange::cxFormatAndSplit(std::string &line, std::string &fwd, std::string &aft, time_t &date, float &coin)
{
	// cx ' | ' 
	std::string::size_type	n;
	
	n = line.find("|");
	if (n != line.rfind("|") || (line[n - 1] != ' ') || (line[n + 1] != ' ')) {
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}
	// split
	fwd = line.substr(0, n - 1);
	aft = line.substr(n + 2);

	// cx fwd
	if (fwd_ok(fwd, date)) {
		std::cout << "Error: bad date input => " << fwd << std::endl; 
		return 1;
	}
	// cx aft
	if (aft_ok(aft, coin)) {
		return 1;
	}

	return 0;
}

void	BitcoinExchange::findRate(time_t date, float coin, std::string strdate)
{
	std::map<std::string, float>::iterator	st = _database.begin();
	std::map<std::string, float>::iterator	ed = _database.end();
	std::map<std::string, float>::iterator temp;

	time_t	db,tmp = 0;
	long	diff1, diff2;
	
	while (st != ed) {
		db = convertDate(st->first);

		if (db == date) {
			std::cout << strdate << " => " << coin << " = " << coin * st->second << std::endl;
			break ;
		}
		else if (db > date) {
			if (st == _database.begin()) {
				std::cout << strdate << " => " << coin << " = " << coin * st->second << std::endl;
			}
			else {
				diff1 = db - date;
				diff2 = date - tmp;
				if (diff1 < diff2)
					std::cout << strdate << " => " << coin << " = " << coin * st->second << std::endl;
				else if (diff2 <= diff1)
					std::cout << strdate << " => " << coin << " = " << coin * temp->second << std::endl;
			}
			break ;
		}
		tmp = db;
		temp = st;
		st++;

	}
	if (st == ed) {
		std::cout << strdate << " => " << coin << " = " << coin * temp->second << std::endl;  
	}


}
