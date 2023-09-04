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
#include <string>

class Zombie {
private :
    std::string name;
public :
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void givename(std::string name);
    void announce(void);
};

Zombie* zombieHorde(int n, std::string name);
#endif