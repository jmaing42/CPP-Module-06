#include "Data.hpp"

Data::Data(int value) : value(value) {}
Data::~Data() {}
Data::Data(const Data &copy) { this->Data::operator=(copy); }
Data &Data::operator=(const Data &copy) {
  this->value = copy.value;
  return *this;
}

int Data::getValue() const { return this->value; }
