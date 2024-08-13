//Let's call a static function from within an object (class instance)
#include <iostream>


class Person {
    public:
        Person();
        Person(int);
        int age();

    private:
        int _age;
};

Person::Person(int __age) {
    this->_age = __age;
    getAgeStatic(this);
}

int Person::age() {
    return this->_age;
}


int main() {

    Person jon(25);


}

int getAgeStatic(Person* p) {
    std::cout << p->age() << std::endl;
}