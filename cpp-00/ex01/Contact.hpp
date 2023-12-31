/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:41 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/19 14:37:15 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
	public:
		Contact();
		Contact(const Contact &);
		~Contact();

		std::string	getFirstname() const;
		std::string	getLastname() const;
		std::string	getNickname() const;
		std::string	getPhonenumber() const;
		std::string	getDarksecret() const;
		bool	addFirstname();
		bool	addLastname();
		bool	addNickname();
		bool	addPhonenumber();
		bool	addDarksecret();
};

#endif
