#include "MutantStack.hpp"
#include <iomanip>

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "TEST ++it and --it " << std::endl;
	++it;
	std::cout << "++it : " << *it << std::endl;
	--it;
	std::cout << "--it : " << *it << std::endl;
	
	
	std::cout << "print all element in stack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	// ============ MY TEST ===================
	MutantStack<int>	my_copy(mstack);

	// print out the copy
	MutantStack<int>::iterator	st = my_copy.begin();
	MutantStack<int>::iterator	ed = my_copy.end();

	std::cout << "MY COPY" << std::endl;
	while (st != ed) {
		std::cout << *st << std::endl;
		st++;
	}
	while (my_copy.size() > 0) {
		my_copy.pop();
	}
	std::cout << "my copy size: " << my_copy.size() << " ori_stack: " << mstack.size() << std::endl;

	my_copy.push(777);
	my_copy.push(787);
	my_copy.push(737);
	my_copy.push(320);
	my_copy.push(330);
	my_copy.push(350);
	my_copy.push(380);

	ed = my_copy.end();
	ite = mstack.end();

	std::cout << "After add new data" << std::endl;
	std::cout << "my copy size: " << my_copy.size() << " ori_stack: " << mstack.size() << std::endl;
	
	for (st = my_copy.begin(); st != ed; st++) {
		std::cout << std::setw(4) << *st;
	}
	std::cout << std::endl;
	for (it = mstack.begin(); it != ite; it++) {
		std::cout << std::setw(4) << *it;
	}
	std::cout << std::endl;

	std::cout << "TEST .empty() : " << my_copy.empty() << std::endl;


	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "Test with string" << std::endl;

	MutantStack<std::string>	stk_str;
	stk_str.push("Hello world");
	stk_str.push("cpp reference");
	stk_str.push("octoSom");
	stk_str.push("Among us");
	stk_str.push("Tiger Balm");

	std::cout << "size = " << stk_str.size() << std::endl;
	MutantStack<std::string>::iterator	st2 = stk_str.begin();
	MutantStack<std::string>::iterator	ed2 = stk_str.end();

	std::cout << "Print all in stack" << std::endl;
	while (st2 != ed2) {
		std::cout << *st2 << std::endl;
		st2++;
	}

	std::cout << "TEST pop out 2" << std::endl;
	stk_str.pop();
	stk_str.pop();
	std::cout << "size now = " << stk_str.size() << std::endl;
	for (st2 = stk_str.begin(); st2 != stk_str.end(); st2++) {
		std::cout << *st2 << std::endl;
	}

	return 0;
}