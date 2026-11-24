#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; ++i)
        materia[i] = NULL;
    std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (other.materia[i])
            materia[i] = other.materia[i]->clone();
        else
            materia[i] = NULL;
    }
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            if (materia[i])
                delete materia[i];
            if (other.materia[i])
                materia[i] = other.materia[i]->clone();
            else
                materia[i] = NULL;
        }
    }
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (materia[i])
            delete materia[i];
    }
    std::cout << "MateriaSource Destructor called" << std::endl;
}

// Learn a new materia by storing its pointer
// in the first available slot
// of the materia array
void MateriaSource::learnMateria(AMateria *m)
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (!materia[i])
        {
            materia[i] = m;
            return;
        }
    }
}

// Create a new materia of the specified type
// by cloning an existing materia
AMateria *MateriaSource::createMateria(std::string const &type)
{
    
    for (size_t i = 0; i < 4; ++i)
    {
        if (materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return NULL;
}
