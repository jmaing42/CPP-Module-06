#ifndef EX00_INT_CONVERT_HPP_INCLUDED
#define EX00_INT_CONVERT_HPP_INCLUDED

#include <string>

#include "ScalarConverter.hpp"

class IntConvert : public ScalarConverter {
private:
  int value;

public:
  static bool isRepresentable(const std::string &stringRepresentation);

  IntConvert(const std::string &stringRepresentation);
  virtual ~IntConvert();
  IntConvert(const IntConvert &copy);
  IntConvert &operator=(const IntConvert &copy);

  virtual char asChar() const;
  virtual int asInt() const;
  virtual float asFloat() const;
  virtual double asDouble() const;
};

#endif
