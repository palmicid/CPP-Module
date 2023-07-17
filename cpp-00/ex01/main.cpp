/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:53:34 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 12:12:20 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	bool		stat = true;
	std::string	cmd = "";
	PhoneBook	phnbook;

	while (stat)
	{
		std::cout << "Phonebook > ";
		std::cin >> cmd;
		if (cmd.compare("ADD") == 0)
			phnbook.addContact();
		else if (cmd.compare("SEARCH") == 0)
			phnbook.searchContact();
		else if (cmd.compare("EXIT") == 0)
			stat = false;
		else
			std::cout << "Only 3 cmd are accepts" << std::endl;
			std::cout << "- ADD : add new contact" << std::endl;
			std::cout << "- SEARCH : display saved contact list, choose number to display more information" << std::endl;
			std::cout << "- EXIT : exit the program" << std::endl;
	}
	return 0;
}
