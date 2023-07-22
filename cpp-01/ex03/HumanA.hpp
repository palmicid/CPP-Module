/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:30:03 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/22 17:07:27 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		_name;
		Weapon			&_weapon;
		// HumanA();

	public:
		// HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	setType(std::string type);
		void	attack() const;
};

#endif
