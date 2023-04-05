#ifndef EX00_FLOAT_CONVERT_HPP_INCLUDED
#define EX00_FLOAT_CONVERT_HPP_INCLUDED

#include <string>

#include "AConvert.hpp"

class FloatConvert : public AConvert {
private:
  double value;

public:
  static bool isRepresentable(const std::string &stringRepresentation);

  FloatConvert(const std::string &stringRepresentation);
  virtual ~FloatConvert();
  FloatConvert(const FloatConvert &copy);
  FloatConvert &operator=(const FloatConvert &copy);

  virtual char asChar() const;
  virtual int asInt() const;
  virtual float asFloat() const;
  virtual double asDouble() const;
};

#endif
