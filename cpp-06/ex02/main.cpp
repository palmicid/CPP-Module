#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base*);
void	identify(Base& );

Base**	createManyBase(int size)
{
	Base **base = new Base*[size];
	
	for (int i = 0; i < size; i++)
	{
		base[i] = generate();
	}
	return base;
}

// ======================================================================

int	main()
{
	srand(time(NULL));
	Base	**manyBase = createManyBase(10);
	std::cout << "Identify by pointer:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		identify(manyBase[i]);
	}

	std::cout << "Identify by reference:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		identify(*manyBase[i]);
	}
	delete [] manyBase;
	return 0;
}

// ======================================================================

Base *generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "Error" << std::endl;
			}
		}
	}
}
