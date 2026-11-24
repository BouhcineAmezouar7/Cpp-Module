#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
    // std::cout << "Weapon created: " << this->type << std::endl;
}

Weapon::~Weapon() {
    // std::cout << "Weapon being destructed" << std::endl;
}

const std::string &Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string newtype) {
    this->type = newtype;
}
