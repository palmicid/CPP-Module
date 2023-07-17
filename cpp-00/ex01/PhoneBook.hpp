/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:55:49 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 15:41:57 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contactarr[8];
		int		count;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(int i);
		void	searchContact(void) const;

}

#endif