/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:11:47 by dabel-co          #+#    #+#             */
/*   Updated: 2023/07/12 11:12:34 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
int main()
{
   Zombie x("pedro");
    x.announce();
    Zombie *r = newZombie("ramon");
    r->announce();
    delete r;
    return(0);
}