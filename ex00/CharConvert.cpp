#include "CharConvert.hpp"

bool CharConvert::isRepresentable(const std::string &stringRepresentation) {
  return stringRepresentation.length() == 1 ||
         (stringRepresentation.length() == 3 &&
          stringRepresentation[0] == '\'' && stringRepresentation[2] == '\'');
}

CharConvert::CharConvert(const std::string &stringRepresentation) {
  if (!CharConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  this->value =
      stringRepresentation[stringRepresentation.length() == 1 ? 0 : 1];
}
CharConvert::~CharConvert() {}
CharConvert::CharConvert(const CharConvert &copy) {
  this->CharConvert::operator=(copy);
}
CharConvert &CharConvert::operator=(const CharConvert &copy) {
  (void)copy;
  return *this;
}

char CharConvert::asChar() const { return value; }
int CharConvert::asInt() const { return static_cast<int>(value); }
float CharConvert::asFloat() const { return static_cast<float>(value); }
double CharConvert::asDouble() const { return static_cast<double>(value); }
