#include <stdio.h>

//Define a new type Rectangle
//This is a user-defined type
//Does not produe any code, only serves as an aid to the compiler
typedef struct rectangle {
    double length; //1st member is length
    double height; //2nd member is width
} Rectangle;


//Forward declaration of RectangleConstructor
void RectangleConstructor(Rectangle*, double, double);

//Forward declaration of rectangleArea
double rectangleArea(Rectangle*);

int main() {

    //Declared rectangle struct
    struct rectangle r1;

    //Declared Rectangle type
    Rectangle r2;

    //Construct r1
    RectangleConstructor(&r1, 10, 20.4);

    //Construct r2
    RectangleConstructor(&r2, 20, 10.38);

    //Calculate the area of r1 and print
    double area = rectangleArea(&r1);
    printf("Area of r1 %.2f\n", area);

    //Calculate the area of r2 and print
    area = rectangleArea(&r2);
    printf("Area of r2 %.2f\n", area);

    
    

}


double rectangleArea(Rectangle *r) {
    
    return r->length * r->height;

}

void RectangleConstructor(Rectangle *r, double l, double h) {

    if(l < 0) {
        r->length = 0;
    } else {
        r->length = l;
    };
    
    if(h < 0) {
        r->length = 0;
    } else {
        r->height = h;
    }
};