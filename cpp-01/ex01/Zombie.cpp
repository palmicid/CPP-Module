/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:12:41 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/20 14:46:16 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string strName)
{
	this->name = strName;
}

Zombie::~Zombie()
{
	std::cout << "zombie " << this->name << " died" << std::endl;
}

void	Zombie::setName(std::string strName)
{
	this->name = strName;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
