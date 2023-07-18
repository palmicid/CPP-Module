/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:55:49 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/18 23:26:25 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			count;
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact(int i);
		void		searchContact(void) const;
		void		showContactList(int &max) const;
		void		printSelectInfo(int i) const;
		std::string	modStr2FitWidth(const std::string str, int width) const;
};

#endif