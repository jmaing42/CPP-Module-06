#ifndef EX00_CHAR_CONVERT_HPP_INCLUDED
#define EX00_CHAR_CONVERT_HPP_INCLUDED

#include <string>

#include "AConvert.hpp"

class CharConvert : public AConvert {
private:
  char value;

public:
  static bool isRepresentable(const std::string &stringRepresentation);

  CharConvert(const std::string &stringRepresentation);
  virtual ~CharConvert();
  CharConvert(const CharConvert &copy);
  CharConvert &operator=(const CharConvert &copy);

  virtual char asChar() const;
  virtual int asInt() const;
  virtual float asFloat() const;
  virtual double asDouble() const;
};

#endif
