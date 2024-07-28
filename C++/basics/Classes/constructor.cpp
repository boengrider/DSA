#include <iostream>

using namespace std;

class Rectangle {
    private:
        int length;
        int width;

    public:
        //non-default constructor. Sets lenght & width to 1
        Rectangle() { length = width = 1; };

        //Prototype of a non default constructor
        //Implementation will be outside of the class using
        //scope resolution operator
        Rectangle(int l, int w);

        //Public method for calculating the area
        //Implementation will be outsie of the class using
        //scope resolution operator
        int area();
        int perimeter();

        //Public getter and setters. Implemented directly in the class definition
        int getLength() { return length; }
        void setLength(int l) { length = l; } 

        //Destructor
        ~Rectangle();
};

//Implementation of constructors and other methods outside of the class
//using scope resolution operator (::)
Rectangle::Rectangle(int l, int w) {
    length = l;
    width = w;
}

int Rectangle::area() {
    return length * width;
}

int Rectangle::perimeter() {
    return 2 * (length + width);
}

Rectangle::~Rectangle() {}


int main() {
    //This declaration is equivalen to Rectangle r = Rectangle(10,5)
    Rectangle r(10,5);

    cout << "area of a rectangle " << r.area() << endl;
    cout << "perimeter of a rectangle " << r.perimeter() << endl;

    r.setLength(20);

    cout << r.getLength() << endl;

    cout << "area of a rectangle " << r.area() << endl;
    cout << "perimeter of a rectangle " << r.perimeter() << endl;
    
}

