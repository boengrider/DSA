#include "myexception.h"
#include <exception>

MyException::MyException() {}

const char* MyException::what() const throw() {
    return "MyException::Error";
}
