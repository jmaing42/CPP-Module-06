#include <sstream>

#include "CharConvert.hpp"
#include "DoubleConvert.hpp"
#include "FloatConvert.hpp"
#include "IntConvert.hpp"
#include "ScalarConverter.hpp"

ScalarConverter *
ScalarConverter::getInstance(std::string &stringRepresentation) {
  if (CharConvert::isRepresentable(stringRepresentation))
    return new CharConvert(stringRepresentation);
  if (IntConvert::isRepresentable(stringRepresentation))
    return new IntConvert(stringRepresentation);
  if (FloatConvert::isRepresentable(stringRepresentation))
    return new FloatConvert(stringRepresentation);
  if (DoubleConvert::isRepresentable(stringRepresentation))
    return new DoubleConvert(stringRepresentation);
  throw ScalarConverter::FormatException();
}

std::string ScalarConverter::toString(char c) {
  std::stringstream ss;
  ss << c;
  return ss.str();
}

std::string ScalarConverter::toString(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

std::string ScalarConverter::toString(float f) {
  std::stringstream ss;
  ss << f;
  return ss.str();
}

std::string ScalarConverter::toString(double f) {
  std::stringstream ss;
  ss << f;
  return ss.str();
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
  this->ScalarConverter::operator=(copy);
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
  (void)copy;
  return *this;
}
