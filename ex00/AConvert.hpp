#ifndef EX00_A_CONVERT_HPP_INCLUDED
#define EX00_A_CONVERT_HPP_INCLUDED

#include <string>

class AConvert {
public:
  static AConvert *getInstance(std::string &stringRepresentation);

  static std::string toString(char c);
  static std::string toString(int i);
  static std::string toString(float f);
  static std::string toString(double f);

  AConvert();
  virtual ~AConvert(){};
  AConvert(const AConvert &copy);
  AConvert &operator=(const AConvert &copy);

  virtual char asChar() const = 0;
  virtual int asInt() const = 0;
  virtual float asFloat() const = 0;
  virtual double asDouble() const = 0;

  class FormatException : public std::exception {};
};

#endif
