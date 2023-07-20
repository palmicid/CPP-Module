/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:35:16 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/20 15:31:54 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	num = 10;
	Zombie *manyZombie = zombieHorde(num, "Mew");
	for (int i = 0; i < num; i++)
	{
		manyZombie[i].announce();
	}
	delete [] manyZombie;
}
