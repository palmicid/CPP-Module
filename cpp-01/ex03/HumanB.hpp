/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:30:45 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/22 12:48:07 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string		_name;
		Weapon			*_weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		std::string	getName();
		void		setWeapon(Weapon &weapon);
		void		attack();
};

#endif
