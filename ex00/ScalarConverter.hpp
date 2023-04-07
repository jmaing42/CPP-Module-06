#ifndef EX00_SCALAR_CONVERTER_HPP_INCLUDED
#define EX00_SCALAR_CONVERTER_HPP_INCLUDED

#include <string>

class ScalarConverter {
public:
  static ScalarConverter *getInstance(std::string &stringRepresentation);

  static std::string toString(char c);
  static std::string toString(int i);
  static std::string toString(float f);
  static std::string toString(double f);

  ScalarConverter();
  virtual ~ScalarConverter(){};
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);

  virtual char asChar() const = 0;
  virtual int asInt() const = 0;
  virtual float asFloat() const = 0;
  virtual double asDouble() const = 0;

  class FormatException : public std::exception {};
};

#endif
