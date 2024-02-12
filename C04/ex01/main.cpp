#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {
    {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    }
    {// ...
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* j = new WrongCat();

    std::cout << j->getType() << std::endl;

    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    }



    int x = 6;

    Animal* animal_array[x];

    for (int i = 0; i < x; i++)
    {
        if ((i % 2) == 0)
            animal_array[i] = new Dog;
        else
            animal_array[i] = new Cat;
    }
     for (int i = 0; i < x; i++)
        delete animal_array[i];
    {
    Dog j = Dog();
    j.get_brain()->set_first_idea("soy original");
    std::cout << j.get_brain()->get_first_idea() << std::endl;
    Dog deepcopy = Dog(j);
    j.get_brain()->set_first_idea("woops no, soy fake");
    std::cout << j.get_brain()->get_first_idea() << std::endl;
    std::cout << deepcopy.get_brain()->get_first_idea() << std::endl;
    
    
    
    }    



    return 0;
}