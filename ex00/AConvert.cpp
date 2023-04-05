#include <sstream>

#include "AConvert.hpp"
#include "CharConvert.hpp"
#include "DoubleConvert.hpp"
#include "FloatConvert.hpp"
#include "IntConvert.hpp"

AConvert *AConvert::getInstance(std::string &stringRepresentation) {
  if (CharConvert::isRepresentable(stringRepresentation))
    return new CharConvert(stringRepresentation);
  if (IntConvert::isRepresentable(stringRepresentation))
    return new IntConvert(stringRepresentation);
  if (FloatConvert::isRepresentable(stringRepresentation))
    return new FloatConvert(stringRepresentation);
  if (DoubleConvert::isRepresentable(stringRepresentation))
    return new DoubleConvert(stringRepresentation);
  throw AConvert::FormatException();
}

std::string AConvert::toString(char c) {
  std::stringstream ss;
  ss << c;
  return ss.str();
}

std::string AConvert::toString(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

std::string AConvert::toString(float f) {
  std::stringstream ss;
  ss << f;
  return ss.str();
}

std::string AConvert::toString(double f) {
  std::stringstream ss;
  ss << f;
  return ss.str();
}

AConvert::AConvert() {}
AConvert::AConvert(const AConvert &copy) { this->AConvert::operator=(copy); }
AConvert &AConvert::operator=(const AConvert &copy) {
  (void)copy;
  return *this;
}
