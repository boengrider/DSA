#include <iostream>

using namespace std;

class Rectangle {
    private:
        int length;
        int width;

    public:
        //Default constructor
        Rectangle() {
            length = width = 1;
        };

        //Prototype of a non default constructor
        Rectangle(int l, int w);

        //Public method for calculating the area
        int area() { 
            return this->length * this->width;
        }
};

int main() { 

    Rectangle r1 = Rectangle();

    cout << r1.area() << endl; // 1

    Rectangle r2 = Rectangle(10, 20);

    cout << r2.area() << endl; // 200
    

}

Rectangle::Rectangle(int l, int w) {
    this->length = l;
    this->width = w;
}