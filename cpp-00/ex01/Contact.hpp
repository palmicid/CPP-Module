/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:56:41 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 15:42:18 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		int			num;
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
		void	addFirstname(const std::string &str);
		void	addlastname(const std::string &str);
		void	addNickname(const std::string &str);
		void	addPhonenumber(const std::string &str);
		void	addDarksecret(const std::string &str);
};

#endif
