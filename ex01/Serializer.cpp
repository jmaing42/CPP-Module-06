#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &copy) {
  this->Serializer::operator=(copy);
}
Serializer &Serializer::operator=(const Serializer &copy) {
  (void)copy;
  return *this;
}

uintptr_t Serializer::serialize(Data *data) {
  return reinterpret_cast<uintptr_t>(data);
}
Data *Serializer::deserialize(uintptr_t data) {
  return reinterpret_cast<Data *>(data);
}
