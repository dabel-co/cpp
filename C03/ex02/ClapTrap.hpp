#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
  // Constructors
  ClapTrap(std::string name); 
  ClapTrap(const ClapTrap &copy);
  // Destructor
  ~ClapTrap();
  // Operators
  ClapTrap &operator=(const ClapTrap &rhs);

  void  attack(const std::string &target); //quita <attack_damage> hit_points (cuesta 1 energy_point)
  void  takeDamage(unsigned int amount); //
  void  beRepaired(unsigned int amount); //añade <amount> hit points

protected :
  std::string name;
  int hit_points; //health
  int energy_points; //para atacar y para curarse
  int attack_damage; //daño del ataque
  
private:
  
  static ClapTrap* claptrap_array[];
  static const int max_claptrap = 3;
  
  ClapTrap* findClapTrap(const std::string &name) const; //const es que no modifico this
  void  addClapTrap();
};

#endif
