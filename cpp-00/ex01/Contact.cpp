/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 22:13:26 by pruangde         ###   ########.fr       */
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

void	Contact::addFirstname(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input First name : ";
		if (std::getline(std::cin, input))
			stat = false;
	}
	this->firstname = input;
}

void	Contact::addLastname(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input Last name : ";
		if (std::getline(std::cin, input))
			stat = false;
	}
	this->lastname = input;
}

void	Contact::addNickname(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input Nickname : ";
		if (std::getline(std::cin, input))
			stat = false;
	}
	this->nickname = input;
}

void	Contact::addPhonenumber(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input Phone number : ";
		if (std::getline(std::cin, input))
			stat = false;
	}
	this->phonenumber = input;
}

void	Contact::addDarksecret(void)
{
	std::string	input;
	bool		stat = true;
	
	while (stat)
	{
		std::cout << "Input Dark secret : ";
		if (std::getline(std::cin, input))
			stat = false;
	}
	this->darkestsecret = input;
}
