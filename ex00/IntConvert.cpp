#include "IntConvert.hpp"
#include <cstddef>
#include <cstdlib>

bool IntConvert::isRepresentable(const std::string &stringRepresentation) {
  int result;
  int sgn = 1;
  size_t i = 0;

  if (!stringRepresentation[0] ||
      (stringRepresentation[0] == '-' && !stringRepresentation[1]) ||
      (stringRepresentation[0] == '-' && stringRepresentation[1] == '0') ||
      (stringRepresentation[0] == '0' && stringRepresentation[1]))
    return false;
  result = 0;
  if (stringRepresentation[0] == '-') {
    sgn = -1;
    i = 1;
  }
  while (stringRepresentation[i]) {
    if (!('0' <= stringRepresentation[i] && stringRepresentation[i] <= '9') ||
        result > INT_MAX / 10 || result < INT_MIN / 10 ||
        (result == INT_MAX / 10 &&
         (stringRepresentation[i] - '0') > (INT_MAX % 10)) ||
        (result == INT_MIN / 10 &&
         (stringRepresentation[i] - '0') > -(INT_MIN % 10)))
      return false;
    result = result * 10 + (stringRepresentation[i++] - '0') * sgn;
  }
  return true;
}

IntConvert::IntConvert(const std::string &stringRepresentation) {
  if (!IntConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  this->value = std::atoi(stringRepresentation.c_str());
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
  return static_cast<char>(value);
}
int IntConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<int>(value);
}
float IntConvert::asFloat() const {
  if (static_cast<float>(value) != value)
    throw AConvert::FormatException();
  return static_cast<float>(value);
}
double IntConvert::asDouble() const {
  if (static_cast<double>(value) != value)
    throw AConvert::FormatException();
  return static_cast<double>(value);
}
