#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <map>
#include <utility>


class BitcoinExchange
{
	private:
		std::multimap<std::string, float>		_database;
		// std::multimap<std::string, float>		_storage;
	
		// helper
		int			init_database();
		int			cxFile(std::string const &);
		int			openFile(std::ifstream &, std::string const &);
		int			readFile(std::ifstream &);
		void		toAddData(std::string const &);
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
