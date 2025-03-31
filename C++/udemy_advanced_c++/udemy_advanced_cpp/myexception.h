#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>

class MyException: public std::exception
{
public:
    MyException();
    virtual const char* what() const throw();
};

#endif // MYEXCEPTION_H
