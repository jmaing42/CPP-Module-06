#include "CharConvert.hpp"

bool CharConvert::isRepresentable(const std::string &stringRepresentation) {
  return stringRepresentation.length() == 3 &&
         stringRepresentation[0] == '\'' && stringRepresentation[2] == '\'';
}

CharConvert::CharConvert(const std::string &stringRepresentation) {
  if (!CharConvert::isRepresentable(stringRepresentation))
    throw AConvert::FormatException();
  this->value = stringRepresentation[1];
}
CharConvert::~CharConvert() {}
CharConvert::CharConvert(const CharConvert &copy) {
  this->CharConvert::operator=(copy);
}
CharConvert &CharConvert::operator=(const CharConvert &copy) {
  this->value = copy.value;
  return *this;
}

char CharConvert::asChar() const {
  if (static_cast<char>(value) != value)
    throw AConvert::FormatException();
  return static_cast<char>(value);
}
int CharConvert::asInt() const {
  if (static_cast<int>(value) != value)
    throw AConvert::FormatException();
  return static_cast<int>(value);
}
float CharConvert::asFloat() const {
  if (static_cast<float>(value) != value)
    throw AConvert::FormatException();
  return static_cast<float>(value);
}
double CharConvert::asDouble() const {
  if (static_cast<double>(value) != value)
    throw AConvert::FormatException();
  return static_cast<double>(value);
}
