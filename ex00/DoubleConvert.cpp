#include "DoubleConvert.hpp"

#include <cmath>
#include <sstream>

bool DoubleConvert::isRepresentable(const std::string &stringRepresentation) {
  if (stringRepresentation == "+inf" || stringRepresentation == "-inf" ||
      stringRepresentation == "nan")
    return true;
  std::stringstream input(stringRepresentation);
  float value;
  input >> value;
  std::stringstream output;
  output.precision(326);
  output << value;
  return output.str() == stringRepresentation;
}

DoubleConvert::DoubleConvert(const std::string &stringRepresentation) {
  if (!DoubleConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  if (stringRepresentation == "+inf") {
    this->value = std::numeric_limits<double>::infinity();
    return;
  }
  if (stringRepresentation == "-inf") {
    this->value = -std::numeric_limits<double>::infinity();
    return;
  }
  if (stringRepresentation == "nanf") {
    this->value = std::numeric_limits<double>::quiet_NaN();
    return;
  }
  std::stringstream input(stringRepresentation);
  input >> this->value;
}
DoubleConvert::~DoubleConvert() {}
DoubleConvert::DoubleConvert(const DoubleConvert &copy) {
  this->DoubleConvert::operator=(copy);
}
DoubleConvert &DoubleConvert::operator=(const DoubleConvert &copy) {
  this->value = copy.value;
  return *this;
}

char DoubleConvert::asChar() const {
  if (static_cast<char>(value) != value)
    throw AConvert::FormatException();
  return static_cast<char>(value);
}
int DoubleConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<int>(value);
}
float DoubleConvert::asFloat() const {
  if (static_cast<float>(value) != value && !std::isnan(value))
    throw AConvert::FormatException();
  return static_cast<float>(value);
}
double DoubleConvert::asDouble() const {
  if (static_cast<double>(value) != value && !std::isnan(value))
    throw AConvert::FormatException();
  return static_cast<double>(value);
}
