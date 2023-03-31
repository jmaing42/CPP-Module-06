#ifndef EX00_CONVERT_HPP_INCLUDED
#define EX00_CONVERT_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

class Convert {
public:
  Convert();
  virtual ~Convert(){};
  Convert(const Convert &copy);
  Convert &operator=(const Convert &copy);

  virtual char asChar() const = 0;
  virtual int asInt() const = 0;
  virtual float asFloat() const = 0;
  virtual double asDouble() const = 0;
};

#endif
