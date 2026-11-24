#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource(); // create MateriaSource
        src->learnMateria(new Ice()); // store Ice materia pointer to array of materias
        src->learnMateria(new Cure()); // store Cure materia pointer to array of materias

        ICharacter* me = new Character("me"); // create Character named "me"
        AMateria* tmp; // temporary pointer to hold created materias
        tmp = src->createMateria("ice"); // create Ice materia
        me->equip(tmp); // equip Ice materia to "me"
        tmp = src->createMateria("cure"); // create Cure materia
        me->equip(tmp); // equip Cure materia to "me"
        ICharacter* bob = new Character("bob"); // create Character named "bob"
        me->use(0, *bob); // use Ice materia on "bob"
        me->use(1, *bob); // use Cure materia on "bob"

        delete bob;
        delete me;
        delete src;
    }

    // {
    //     // * Create a Character
    //     ICharacter *bruno = new Character("Bruno");

    //     // * Learn and create Some Materia and equip it
    //     AMateria *tmp;
    //     IMateriaSource *src = new MateriaSource();

    //     // * learn
    //     src->learnMateria(new Ice());
    //     // * create
    //     tmp = src->createMateria("ice");
    //     // * equip it
    //     bruno->equip(tmp);

    //     src->learnMateria(new Cure());
    //     tmp = src->createMateria("cure");
    //     bruno->equip(tmp);

    //     // * careate another character to use on him the materia
    //     ICharacter *enemy = new Character("enemy");

    //     // * attack
    //     bruno->use(0, *enemy);
    //     // * heal
    //     bruno->use(1, *enemy);
    //     // * remove cure from inventory
    //     bruno->unequip(1);

    //     // * delete all allocation memory
    //     delete enemy;
    //     delete src;
    //     delete bruno;
    // }

    // {
    //     // * Create a Character
    //     Character bruno("Bruno");

    //     // * Learn and create Some Materia and equip it
    //     AMateria *tmp;
    //     MateriaSource src;

    //     // * learn
    //     src.learnMateria(new Ice());
    //     // * create
    //     tmp = src.createMateria("ice");
    //     // * equip it
    //     bruno.equip(tmp);

    //     src.learnMateria(new Cure());
    //     tmp = src.createMateria("cure");
    //     bruno.equip(tmp);

    //     // * careate another character to use on him the materia
    //     Character enemy("enemy");

    //     // * attack
    //     bruno.use(0, enemy);
    //     bruno.use(1, enemy);
    // }

    // craete 5 materia to test the limit and equip function and unequip
    // {
    //     Character hero("Hero");
    //     MateriaSource source;
    //     AMateria *tmp;
    //     source.learnMateria(new Ice());
    //     source.learnMateria(new Cure());
    //     for (int i = 0; i < 5; ++i)
    //     {
    //         tmp = source.createMateria("ice");
    //         hero.equip(tmp);
    //     }
    //     // unequip index 2
    //     hero.unequip(2);
    //     // try to equip again the last created materia
    //     tmp = source.createMateria("ice");
    //     hero.equip(tmp);
    // }

    return 0;
}