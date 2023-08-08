/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:11:32 by dabel-co          #+#    #+#             */
/*   Updated: 2023/07/12 12:51:30 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {
private :
    std::string name;
public :
    Zombie(std::string name);
    ~Zombie(void);
    Zombie* newZombie(std::string name);
    void randomChump(std::string name);
    void announce(void);

};
#endif