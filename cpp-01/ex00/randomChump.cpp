/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:13:24 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/20 00:00:07 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// creates a zombie, name it, and announces itself
void	randomChump( std::string name )
{
	Zombie	tmpZombie(name);
	tmpZombie.announce();
}
