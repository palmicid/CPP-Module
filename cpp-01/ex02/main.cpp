/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:36:13 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/21 21:11:52 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string const str = "HI THIS IS BRAIN";
	std::string const *stringPTR = &str;
	std::string const &stringREF = str;

	std::cout << "Mem-address            = " << &str << std::endl;
	std::cout << "Mem-add held by strPTR = " << stringPTR << std::endl;
	std::cout << "Mem-add held by strREF = " << &stringREF << std::endl;

	std::cout << "Value of the string var    = " << str << std::endl;
	std::cout << "Value pointed to by strPTR = " << *stringPTR << std::endl;
	std::cout << "Value pointed to by strREF = " << stringREF << std::endl;

	return (0);
}
