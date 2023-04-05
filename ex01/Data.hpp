#ifndef EX01_DATA_HPP_INCLUDED
#define EX01_DATA_HPP_INCLUDED

class Data {
private:
  int value;

public:
  Data(int value = 42);
  ~Data();
  Data(const Data &copy);
  Data &operator=(const Data &copy);

  int getValue() const;
};

#endif
