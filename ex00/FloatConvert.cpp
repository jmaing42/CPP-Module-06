#include "FloatConvert.hpp"

#include <cmath>
#include <sstream>

bool FloatConvert::isRepresentable(const std::string &stringRepresentation) {
  if (stringRepresentation == "+inff" || stringRepresentation == "-inff" ||
      stringRepresentation == "nanf")
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
    throw ScalarConverter::FormatException();
  if (stringRepresentation == "+inff") {
    this->value = std::numeric_limits<float>::infinity();
    return;
  }
  if (stringRepresentation == "-inff") {
    this->value = -std::numeric_limits<float>::infinity();
    return;
  }
  if (stringRepresentation == "nanf") {
    this->value = std::numeric_limits<float>::quiet_NaN();
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
    throw ScalarConverter::FormatException();
  return static_cast<char>(value);
}
int FloatConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw ScalarConverter::FormatException();
  return static_cast<int>(value);
}
float FloatConvert::asFloat() const {
  if (static_cast<float>(value) != value && !std::isnan(value))
    throw ScalarConverter::FormatException();
  return static_cast<float>(value);
}
double FloatConvert::asDouble() const {
  if (static_cast<double>(value) != value && !std::isnan(value))
    throw ScalarConverter::FormatException();
  return static_cast<double>(value);
}
