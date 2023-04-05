#include <cstdlib>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate() {
  switch (rand() % 3) {
  case 0:
    return new A();
  case 1:
    return new B();
  default:
    return new C();
  }
}

void identify(Base *obj) {
  if (dynamic_cast<A *>(obj))
    std::cout << "A" << std::endl;
  if (dynamic_cast<B *>(obj))
    std::cout << "B" << std::endl;
  if (dynamic_cast<C *>(obj))
    std::cout << "C" << std::endl;
}

void identify(Base &obj) {
  try {
    (volatile void)dynamic_cast<A &>(obj);
    std::cout << "A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    (volatile void)dynamic_cast<B &>(obj);
    std::cout << "B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    (volatile void)dynamic_cast<C &>(obj);
    std::cout << "C" << std::endl;
  } catch (std::exception &e) {
  }
}

int main() {
  srand(time(NULL));
  {
    Base *base = generate();
    identify(base);
    identify(*base);
  }
}
