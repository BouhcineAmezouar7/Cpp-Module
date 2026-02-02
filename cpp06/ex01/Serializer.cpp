#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
    ;
}
Serializer::~Serializer() {}

// the reinterpret_cast operator is used to convert any pointer type to any other pointer type, even of unrelated classes.
// It can also be used to convert a pointer to an integer type and vice versa.
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

