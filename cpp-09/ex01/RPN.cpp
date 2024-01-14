#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string &input)
{
	_box = "";

	if (input.size() == 0) {
		std::cout << "Error" << std::endl;
		return ;
	}

	// cx digit and sign
	if (cxDigit_operator(input)) {
		std::cout << "Error" << std::endl;
		return ;
	}
	// split input
	if (split_input(input)) {
		std::cout << "Error" << std::endl;
		return ;
	}
	// push2stack and calculate
	if (stackCalculator()) {
		std::cout << "Error" << std::endl;
		return ;
	}


}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN::~RPN() {}

RPN&	RPN::operator=(RPN const &other)
{
	if (this == &other)
		return *this;
	return *this;
}

// =================================================================================

bool	isOperator(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}


bool	RPN::cxDigit_operator(std::string &raw)
{
	for (std::string::size_type n = 0; n < raw.length(); n++) {
		if (!isdigit(raw[n]) && !isOperator(raw[n]) && raw[n] != ' ')
			return 1;
	}
	return 0;
}


bool	RPN::split_input(std::string &raw) 
{
	std::string			block = "";
	std::stringstream	ss(raw);

	while (std::getline(ss, block, ' ')) {
		if (block.length() > 1)
			return 1;
		_box = _box + block;
	}
	if (_box.size() == 0)
		return 1;

	return 0;
}


bool	RPN::toCal(char c)
{
	int	a, b;
	if (_stk.size() < 2)
		return 1;
	b = _stk.top();
	_stk.pop();
	a = _stk.top();
	_stk.pop();

	switch (c)
	{
	case '+':
		a+=b;
		break;
	case '-':
		a-=b;
		break;
	case '*':
		a*=b;
		break;
	case '/':
		a/=b;
		break;
	
	default:
		break;
	}
	_stk.push(a);

	return 0;
}

bool	RPN::stackCalculator()
{
	int		tmp;
	
	for (std::string::size_type n = 0; n < _box.length(); n++)
	{
		if (isOperator(_box[n])) {
			if (toCal(_box[n])) {
				return 1;
			}
		}
		else {

			tmp = _box[n] - '0';
			_stk.push(tmp);
		}
	}
	if (_stk.size() > 1)
		return 1;
	
	std::cout << _stk.top() << std::endl;

	return 0;
}

