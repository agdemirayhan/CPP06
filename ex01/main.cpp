#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.id = 42;
    originalData.name = "ChatGPT";

    std::cout << "Original Data address: " << &originalData << "\n";
    std::cout << "Original Data content: { id: " << originalData.id << ", name: " << originalData.name << " }\n";

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << deserializedData << "\n";
    std::cout << "Deserialized Data content: { id: " << deserializedData->id << ", name: " << deserializedData->name << " }\n";

    if (deserializedData == &originalData)
        std::cout << "Success: Pointers match!\n";
    else
        std::cout << "Failure: Pointers do not match.\n";

    return 0;
}
