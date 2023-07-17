/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 13:15:07 by pruangde         ###   ########.fr       */
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
	return (firstname);
}

std::string	Contact::getLastname() const
{
	return (lastname);
}

std::string	Contact::getNickname() const
{
	return (nickname);
}

std::string	Contact::getPhonenumber() const
{
	return (phonenumber)
}

std::string	Contact::getDarksecret() const
{

}

void	Contact::addFirstname(std::string str)
{
	firstname = str;
}

void	Contact::addlastname()
{

}

void	Contact::addNickname()
{

}

void	Contact::addPhonenumber()
{

}

void	Contact::addDarksecret()
{

}
