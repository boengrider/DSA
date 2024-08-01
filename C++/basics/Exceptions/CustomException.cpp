#include <iostream>
#include <exception>

using namespace std;

class Person {
    public:
        Person(string, int);
        Person(string, int, int);
        int getAge();
        int setAge(int);
        int makeOlder(int);
        int makeYounger(int);
    private:
        string name;
        int age;
        int limit;

};

class PersonException : public exception {
    public:
        PersonException(int);
        virtual const char* what() const throw();
    private:
        int errorCode;
};

PersonException::PersonException(int _errorCode) {
    this->errorCode = _errorCode;

}

const char* PersonException::what() const throw() { 
    switch (this->errorCode)
    {
    case 1:
        return "Person age below zero";
        break;

    case 2:
        return "Person age too high";
        break;
    
    default:
        break;
    }
}


Person::Person(string _name, int _age) {
    this->name = _name;
    this->age = _age;
    this->limit = 120;
}

Person::Person(string _name, int _age, int _limit) {
    this->name = _name;
    this->age = _age;
    this->limit = _limit;
}

int Person::getAge() {
    return this->age;
}

int Person::setAge(int _age) {
    if(_age > this->limit) {
        throw PersonException(1);
    } else {
        this->age = _age;
        return this->age;
    }
}

int Person::makeOlder(int _age) {
    if(this->age + _age > this->limit) {
        throw PersonException(1);
    } else {
        return this->setAge(this->age + _age);
    }
}

int Person::makeYounger(int _age) {
    if(this->age - _age < 0) {
        throw PersonException(2);
    } else {
        return this->setAge(this->age - _age);
    }
}