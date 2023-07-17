/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 15:36:43 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	num = -1;
	firstname = "";
	lastname = "";
	nickname = "";
	phonenumber = "";
	darkestsecret = "";
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

void	Contact::addFirstname(const std::string &str)
{
	this->firstname = str;
}

void	Contact::addlastname(const std::string &str)
{
	this->lastname = str;
}

void	Contact::addNickname(const std::string &str)
{
	this->nickname = str;
}

void	Contact::addPhonenumber(const std::string &str)
{
	this->phonenumber = str;
}

void	Contact::addDarksecret(const std::string &str)
{
	this->darkestsecret = str;
}
