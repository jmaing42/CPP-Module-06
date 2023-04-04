#include "IntConvert.hpp"

bool IntConvert::isRepresentable(const std::string &stringRepresentation) {}

IntConvert::IntConvert(const std::string &stringRepresentation) {
  if (!IntConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  // TODO:
  this->value = 0;
}
IntConvert::~IntConvert() {}
IntConvert::IntConvert(const IntConvert &copy) {
  this->IntConvert::operator=(copy);
}
IntConvert &IntConvert::operator=(const IntConvert &copy) {
  this->value = copy.value;
  return *this;
}

char IntConvert::asChar() const {
  if (static_cast<char>(value) != value)
    throw AConvert::FormatException();
  return value;
}
int IntConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<int>(value);
}
float IntConvert::asFloat() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<float>(value);
}
double IntConvert::asDouble() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<double>(value);
}
