#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include "AConvert.hpp"

void doWork(std::string string) {
  const AConvert *const convert = AConvert::getInstance(string);
  try {
    try {
      std::stringstream ss;
      ss << "char: " << convert->asChar();
      std::cout << ss.str() << std::endl;
    } catch (std::exception &e) {
      std::cout << "impossible" << std::endl;
    }
    try {
      std::stringstream ss;
      ss << "int: " << convert->asInt();
      std::cout << ss.str() << std::endl;
    } catch (std::exception &e) {
      std::cout << "impossible" << std::endl;
    }
    try {
      std::stringstream ss;
      ss << "float: " << convert->asFloat();
      std::cout << ss.str() << std::endl;
    } catch (std::exception &e) {
      std::cout << "impossible" << std::endl;
    }
    try {
      std::stringstream ss;
      ss << "double: " << convert->asDouble();
      std::cout << ss.str() << std::endl;
    } catch (std::exception &e) {
      std::cout << "impossible" << std::endl;
    }
  } catch (std::exception &e) {
    delete convert;
    throw e;
  }
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    doWork(argv[i]);
  }
}
