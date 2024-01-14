#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <map>
#include <utility>
#include <ctime>


class BitcoinExchange
{
	private:
		std::map<std::string, float>		_database;
	
		// helper
		int			init_database();
		int			cxFile(std::string const &);
		int			openFile(std::ifstream &, std::string const &);
		void		toAddData(std::string const &);
		void 		readFile(std::ifstream &);
		int			cxFormatAndSplit(std::string &, std::string &, std::string &, time_t &, float &);
		void		findRate(time_t, float, std::string);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &);
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();

		BitcoinExchange&	operator=(BitcoinExchange const &);
		

		class DatabaseFailException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class OpenFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


};




#endif
