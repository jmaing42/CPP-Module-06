#ifndef EX01_SERIALIZER_HPP_INCLUDED
#define EX01_SERIALIZER_HPP_INCLUDED

#include "Data.hpp"

#include <cstdint>

class Serializer {
public:
  Serializer();
  ~Serializer();
  Serializer(const Serializer &copy);
  Serializer &operator=(const Serializer &copy);

  static std::uintptr_t serialize(Data *data);
  static Data *deserialize(uintptr_t data);
};

#endif
