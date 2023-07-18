/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:00 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 22:08:06 by pruangde         ###   ########.fr       */
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
	this->contacts[i].addFirstname();
	this->contacts[i].addLastname();
	this->contacts[i].addNickname();
	this->contacts[i].addPhonenumber();
	this->contacts[i].addDarksecret();
}

void	PhoneBook::searchContact(void) const
{
	int	tmp;

	if (this->count > 8)
		tmp = 8;
	else
		tmp = this->count;
	for (int x = 0; x < tmp; x++)
	{
		std::cout << "|" << std::setw(10) << x + 1;
		std::cout << "|" << std::setw(10) << this->contacts[x].getFirstname();
		std::cout << "|" << std::setw(10) << this->contacts[x].getLastname();
		std::cout << "|" << std::setw(10) << this->contacts[x].getNickname();
		std::cout << "|" << std::endl;
	}
}
