#include "FloatConvert.hpp"

#include <sstream>

bool FloatConvert::isRepresentable(const std::string &stringRepresentation) {
  if (stringRepresentation == "+inff" || stringRepresentation == "-inff")
    return true;
  std::stringstream input(stringRepresentation);
  double value;
  input >> value;
  std::stringstream output;
  output.precision(47);
  output << value;
  return output.str() == stringRepresentation;
}

FloatConvert::FloatConvert(const std::string &stringRepresentation) {
  if (!FloatConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  if (stringRepresentation == "+inff") {
    this->value = std::numeric_limits<float>::infinity();
    return;
  }
  if (stringRepresentation == "-inff") {
    this->value = -std::numeric_limits<float>::infinity();
    return;
  }
  std::stringstream input(stringRepresentation);
  input >> this->value;
}
FloatConvert::~FloatConvert() {}
FloatConvert::FloatConvert(const FloatConvert &copy) {
  this->FloatConvert::operator=(copy);
}
FloatConvert &FloatConvert::operator=(const FloatConvert &copy) {
  this->value = copy.value;
  return *this;
}

char FloatConvert::asChar() const {
  if (static_cast<char>(value) != value)
    throw AConvert::FormatException();
  return static_cast<char>(value);
}
int FloatConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<int>(value);
}
float FloatConvert::asFloat() const {
  if (static_cast<float>(value) != value)
    throw AConvert::FormatException();
  return static_cast<float>(value);
}
double FloatConvert::asDouble() const {
  if (static_cast<double>(value) != value)
    throw AConvert::FormatException();
  return static_cast<double>(value);
}
