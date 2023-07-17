/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:55:49 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 11:50:41 by pruangde         ###   ########.fr       */
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
		void	initData(void);
		void	addContact(void);
		void	searchContact(void) const;
		void	
}


#endif