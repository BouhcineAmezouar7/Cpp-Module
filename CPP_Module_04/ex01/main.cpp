#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j; // should not create a leak
        delete i;
    }

    // std::cout << "===========================================" << std::endl;

    // {
    //     Animal *animal[4];
    //     for (int i = 0; i < 4; i++){
    //         if (i < 2){
    //             animal[i] = new Dog();
    //         } else {
    //             animal[i] = new Cat();
    //         }
    //     }

    //     // * Make Sound
    //     for (int i = 0; i < 4; i++){
    //         animal[i]->makeSound();
    //     }

    //     // * Free the array of animal
    //     for (int i = 0; i < 4; i++){
    //         delete animal[i];
    //     }
    // }

    // std::cout << "===========================================" << std::endl;

    // {
    //     // * Without pointer (Object Slicing)
    //     Animal monster[2];
    //     for (int i = 0; i < 2; i++){
    //         if (i < 1){
    //             monster[i] = Dog();
    //         }
    //         monster[i] = Cat();
    //     }

    //     // * Make Sound
    //     for (int i = 0; i < 2; i++){
    //         monster[i].makeSound();
    //     }
    // }

    return 0;
}