#ifndef EX00_DOUBLE_CONVERT_HPP_INCLUDED
#define EX00_DOUBLE_CONVERT_HPP_INCLUDED

#include <string>

#include "AConvert.hpp"

class DoubleConvert : public AConvert {
private:
  double value;

public:
  static bool isRepresentable(const std::string &stringRepresentation);

  DoubleConvert(const std::string &stringRepresentation);
  virtual ~DoubleConvert();
  DoubleConvert(const DoubleConvert &copy);
  DoubleConvert &operator=(const DoubleConvert &copy);

  virtual char asChar() const;
  virtual int asInt() const;
  virtual float asFloat() const;
  virtual double asDouble() const;
};

#endif
