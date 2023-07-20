/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:11:45 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/20 00:55:14 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// zombie in randomChump died since the function over
// newZombie still alive in {} untill deleted

int	main(void)
{
	Zombie	*zomPika = newZombie("Pikachu");
	randomChump("Fushikidane");
	{
		randomChump("Zenigame");
		Zombie	*zomHito = newZombie("Hitokage");
		delete zomHito;
	}
	zomPika->announce();
	delete zomPika;
}
