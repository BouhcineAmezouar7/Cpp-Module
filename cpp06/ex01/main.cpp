#include "Serializer.hpp"

int main()
{
    Data data;
    data.nb = 42;
    data.name = "Hello, World!";

    // Serialize the pointer to Data
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize back to Data pointer
    Data *deserializedData = Serializer::deserialize(raw);

    // Output the results
    std::cout << "Original Data: nb = " << data.nb << ", name = " << data.name << std::endl;
    std::cout << "Deserialized Data: nb = " << deserializedData->nb << ", name = " << deserializedData->name << std::endl;

    return 0;
}