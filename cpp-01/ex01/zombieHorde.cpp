/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:35:43 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/20 14:48:10 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *newHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		newHorde[i].setName(name);
	}
	return (newHorde);
}
