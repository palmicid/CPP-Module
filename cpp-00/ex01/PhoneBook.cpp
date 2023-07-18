/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:00 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/19 02:53:10 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook()
{
	this->count = 0;
}

// destructor
PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(int i)
{
	std::string	str;
	
	this->count += 1;
	if (!this->contacts[i].addFirstname())
		return ;
	if (!this->contacts[i].addLastname())
		return ;
	if (!this->contacts[i].addNickname())
		return ;
	if (!this->contacts[i].addPhonenumber())
		return ;
	if (!this->contacts[i].addDarksecret())
		return ;
}

void	PhoneBook::searchContact(void) const
{
	int			max;
	std::string	tmp;
	bool		stat = true;

	if (this->count > 8)
		max = 8;
	else
		max = this->count;
	showContactList(max);
	while (stat)
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			return ;
		}
		std::cout << "Which index : ";
		std::getline(std::cin, tmp);
		if (!std::cin.eof() && !std::cin.fail())
		{
			if (tmp.length() == 1 && (tmp[0] > '0' && tmp[0] <= '9'))
			{
				if (int((tmp[0] -'0') - 1) < max)
					stat = false;
				else
					std::cout << "PLZ INPUT VALID INDEX !!!" << std::endl;
			}
			else
				std::cout << "PLZ INPUT VALID INDEX !!!" << std::endl;
		}
		else if (std::cin.fail() && !std::cin.eof())
		{
			std::cout << "PLZ INPUT VALID INDEX !!!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			std::cout << "PLZ INPUT VALID INDEX !!!" << std::endl;
	}
	printSelectInfo(int((tmp[0] -'0') - 1));
}

void	PhoneBook::showContactList(int &max) const
{
	int			width = 10;

	for (int x = 0; x < max; x++)
	{
		std::cout << "|" << std::setw(width) << x + 1;
		std::cout << "|" << std::setw(width) << modStr2FitWidth(this->contacts[x].getFirstname(), width);
		std::cout << "|" << std::setw(width) << modStr2FitWidth(this->contacts[x].getLastname(), width);
		std::cout << "|" << std::setw(width) << modStr2FitWidth(this->contacts[x].getNickname(), width);
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::printSelectInfo(int i) const
{
	std::cout << "First name     : " << this->contacts[i].getFirstname() << std::endl;
	std::cout << "Last name      : " << this->contacts[i].getLastname() << std::endl;
	std::cout << "Nickname       : " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number   : " << this->contacts[i].getPhonenumber() << std::endl;
	std::cout << "Darkest secret : " << this->contacts[i].getDarksecret() << std::endl;
}


std::string	PhoneBook::modStr2FitWidth(const std::string str, int width) const
{
	char	ret[width + 1];
	
	if (str.length() <= (unsigned int)width)
		return str;
	for (int i = 0; i < width; i++)
	{
		ret[i] = str[i];
	}
	ret[width - 1] = '.';
	ret[width] = '\0';
	return ret;
}
