#include <sstream>

#include "AConvert.hpp"

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
