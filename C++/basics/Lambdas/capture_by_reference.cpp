#include <iostream>

class Rectangle {
    public:
        Rectangle();
        Rectangle(int,int);
        int width();
        int length();
        void setWidth(int);
        void setLength(int);

    private:
        int _width;
        int _length;
};

Rectangle::Rectangle(int width, int length) {
    this->_width = width;
    this->_length = length;
};

int Rectangle::width() {
    return this->_width;
}

int Rectangle::length() {
    return this->_length;
}

void Rectangle::setWidth(int width) {
    this->_width = width;
}

void Rectangle::setLength(int length) {
    this->_length = length;
}

class Circle {
    public:
        Circle();
        Circle(int);
        int _radius;
};

Circle::Circle(int radius) {
    this->_radius = radius;
}



int main() {

    Rectangle r(10,20);

    
   

    std::cout << "Initial width -> " << r.width() << std::endl;
    std::cout << "Initial length -> " << r.length() << std::endl;

    //Capture by reference
    [&r](int w, int l){
        r.setWidth(w);
        r.setLength(l);
    }(100,200);

    std::cout << "Modified width -> " << r.width() << std::endl;
    std::cout << "Modified length -> " << r.length() << std::endl;

    int area;
    //Capture by value
    //Return area
    area = [r]() mutable ->int{
        return r.length() * r.width();
    }();

    std::cout << "Area -> " << area << std::endl;



    Circle c(25);

    //Capture by value 
    //Modify radius
    [c](int newRadius) mutable {
        c._radius = newRadius;
        std::cout << c._radius << std::endl;
    }(35);

    std::cout << c._radius << std::endl;

    




  
}