/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:29:27 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/22 12:48:15 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string		_type;
	public:
		Weapon();
		Weapon( std::string type );
		~Weapon();

		const std::string	getType();
		void				setType(std::string type);
};

#endif
