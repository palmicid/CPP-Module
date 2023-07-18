/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/19 01:09:32 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{	
}

std::string	Contact::getFirstname() const
{
	return (this->firstname);
}

std::string	Contact::getLastname() const
{
	return (this->lastname);
}

std::string	Contact::getNickname() const
{
	return (this->nickname);
}

std::string	Contact::getPhonenumber() const
{
	return (this->phonenumber);
}

std::string	Contact::getDarksecret() const
{
	return (this->darkestsecret);
}

bool	Contact::addFirstname(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input First name : ";
		if (!std::getline(std::cin, input))
			return false;
		else
		{
			if (input.length() != 0)
				break ;
		}
	}
	this->firstname = input;
	return stat;
}

bool	Contact::addLastname(void)
{
	std::string	input;
	bool		stat = true;

	while (stat)
	{
		std::cout << "Input Last name : ";
		if (!std::getline(std::cin, input))
			return false;
		else
		{
			if (input.length() != 0)
				break ;
		}
	}
	this->lastname = input;
	return stat;
}

bool	Contact::addNickname(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{	
		std::cout << "Input Nickname : ";
		if (!std::getline(std::cin, input))
			return false;
		else
		{
			if (input.length() != 0)
				break ;
		}
	}
	this->nickname = input;
	return stat;
}

bool	Contact::addPhonenumber(void)
{
	std::string	input;
	bool		stat = true;
	bool		digit = false;

	while (stat && !digit)
	{
		std::cout << "Input Phone number : ";
		if (!std::getline(std::cin, input))
			return false;
		else
		{
			if (input.length() == 0)
				continue ;
			for (int i = 0; input[i]; i++)
			{
				if (input[i] >= '0' && input[i] <= '9')
					digit = true;
				else
				{
					digit = false;
					break ;
				}
			}
		}
	}
	this->phonenumber = input;
	return stat;
}

bool	Contact::addDarksecret(void)
{
	std::string	input;
	bool		stat = true;

	while (stat)
	{
		std::cout << "Input Dark secret : ";
		if (!std::getline(std::cin, input))
			return false;
		else
		{
			if (input.length() != 0)
				break ;
		}
	}
	this->darkestsecret = input;
	return stat;
}
