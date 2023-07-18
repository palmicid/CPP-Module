/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:53:34 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/18 08:32:53 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "PhoneBook.hpp"

void	guideMessage()
{
	std::cout << "Only 3 cmd are accepts, and plz type exactly same as show below" << std::endl;
	std::cout << "- ADD : add new contact" << std::endl;
	std::cout << "- SEARCH : display saved contact list, choose number to display more information" << std::endl;
	std::cout << "- EXIT : exit the program" << std::endl;
}

// i for know last list
int	main()
{
	bool		stat = true;
	PhoneBook	phnbook;
	std::string	cmd;
	int			i = 0;

	while (stat)
	{
		std::cout << "PhoneBook 0.5 > ";
		std::getline(std::cin, cmd);
		if (!std::cin.eof())
		{
			if (cmd.compare("ADD") == 0)
			{
				phnbook.addContact(i % 8);
				i++;
			}
			else if (cmd.compare("SEARCH") == 0)
				phnbook.searchContact();
			else if (cmd.compare("EXIT") == 0)
				stat = false;
			else
				guideMessage();
		}
		if (std::cin.fail() || std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// stat = false;
		}
	}
	return 0;
}
