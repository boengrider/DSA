/*
This file contains DSA/C/basics/Functions/struct_as_a_parameter.c program
modified into C++ program
 */

#include <iostream>

using namespace std;

//In C this would be a simple structure containing
//two members
class Rectangle {

    private:
        int width;
        int lenght;

    public:
        Rectangle(int width, int lenght) {
            this->width = width;
            this->lenght = lenght;
        }

        void changeRectangleLenght(int lenght) {
            this->lenght = lenght;
        }

        void changeRectangleWidth(int width) {
            this->width = width;
        }

        int area() {
            return this->lenght * this->width;
        }

};

int main() {

    //Primary constructor is called here
    Rectangle rect = {10, 20};


    std::cout << rect.area() << std::endl;

    rect.changeRectangleLenght(100);
    rect.changeRectangleWidth(100);

    std::cout << rect.area() << std::endl;

}

