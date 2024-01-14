#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
	private:
		std::stack<int>		_stk;
		std::string			_box;
	
		bool	cxDigit_operator(std::string &);
		bool	split_input(std::string &);
		bool	stackCalculator();
		bool	toCal(char c);
	public:
		RPN();
		RPN(std::string &);
		RPN(RPN const &);
		~RPN();

		RPN	&operator=(RPN const &);
};



#endif