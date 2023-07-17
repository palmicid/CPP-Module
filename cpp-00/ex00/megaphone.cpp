/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:19:42 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/17 01:56:27 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// char	is_smallAlpha_ToUpper(char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return c;
// }

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				av[i][j] = toupper(av[i][j]);
		}
		for (int i = 1; i < ac; i++)
			std::cout << av[i];
		std::cout << std::endl;
	}
	else if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
