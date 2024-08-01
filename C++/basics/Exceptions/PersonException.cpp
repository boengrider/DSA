#include <iostream>

using namespace std;

class personException : exception {
    public:
        string message;
        personException(const char* _message) {
            message = _message;
        }
};

class Person {
    public:
        Person(int);
        int increaseAge(int);
        int decreaseAge(int);
        int getAge();
        int setAge(int);

    private:   
        int age;

    
};


int Person::increaseAge(int _a) {
    age += _a;
    return age;
}

int Person::decreaseAge(int _a) {
    if(age - _a < 0) {
        throw personException("You can't decrease age below zero");
    } else {
        age -= _a;
        return age;
    }

}

int Person::getAge() {
    return age;
}

int Person::setAge(int _a) {
    age = _a;
    return age;
}

Person::Person(int _a) {
    age = _a;
}

//third function throwing exception
void third() {
    throw 1000;
}

void second() {
    third();
}

void first() {
    second();
}





int main() {


    try
    {
        first();
    }
    catch(int e)
    {
        cerr << "Excepction " << e << " occured" << endl;
    }
    

    //Allocate one person on the stack
    Person jonDoe(32);

    try
    {
        cout << jonDoe.getAge() << endl;
        cout << jonDoe.decreaseAge(31) << endl;
        //jonDoe.decreaseAge(2);
    }
    catch(const personException& e)
    {
        cerr << e.message << endl;
    }
    
    return 0;
}