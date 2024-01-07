#include "Span.hpp"
#include <iostream>
#include <cstdlib>

// From subject
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// longest not same as in subject	

// int	main()
// {
// 	// int	arr[20] = { 6,23,6345,87,22,1,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
// 	int	arr[20] = { 6,23,6345,87,22,1,3,4 };
	
// 	Span	sp(20);
// 	for (int i = 0; i < 8; i++) {
// 		try {
// 			sp.addNumber(arr[i]);
// 		}
// 		catch (std::exception &e) {
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
// 	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
// 	std::cout << "longest span: " << sp.longestSpan() << std::endl;
// 	try {
// 		sp.addNumber(-234);
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	sp.printVector();
// 	std::cout << "============================================================" << std::endl;

// 	std::vector<int> vec;
// 	vec.push_back(-1);
// 	vec.push_back(-2);
// 	vec.push_back(-3);
// 	vec.push_back(4);
// 	vec.push_back(-5);

// 	Span	spcp(sp);
// 	std::cout << "copy: " << std::endl;
// 	spcp.printVector();
	
// 	try {
// 		sp.addNumber(vec.begin(), vec.end());
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "----------- After add vector -------- " << std::endl;
// 	sp.printVector();

// 	std::cout << "copy after the souce add more vector: " << std::endl;
// 	spcp.printVector();
	
// 	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
// 	std::cout << "longest span: " << sp.longestSpan() << std::endl;

// 	return 0;
// }