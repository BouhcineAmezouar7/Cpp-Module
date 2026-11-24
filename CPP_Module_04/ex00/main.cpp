#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\n------------ types ------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n---------- sounds ----------" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "------- wrong animal test -------" << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << "\n------------ types ------------" << std::endl;
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << "\n---------- sounds ----------" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound(); // will output the wrong animal sound!

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
