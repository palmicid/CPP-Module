#ifndef MYSED_HPP
# define MYSED_HPP

# include <iostream>

class MySed
{
	private:
		std::string	_fname;
		// std::ifstream	_fileIn;
		// std::ofstream	_fileOut;
		std::string _s1;
		std::string	_s2;
		

	public:
		MySed(std::string fname, std::string s1, std::string s2);
		~MySed();

		void	myReplace();


};


#endif