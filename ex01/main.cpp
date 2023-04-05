#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  {
    Data *originalData = new Data();
    uintptr_t serializedData = Serializer::serialize(originalData);
    Data *deserializedData = Serializer::deserialize(serializedData);
    std::cout << "original data: " << originalData->getValue() << std::endl;
    std::cout << "deserialized data: " << deserializedData->getValue()
              << std::endl;
    *originalData = Data(0);
    std::cout << "original data: " << originalData->getValue() << std::endl;
    std::cout << "deserialized data: " << deserializedData->getValue()
              << std::endl;
    delete originalData;
  }
}
