#include <stdio.h>


typedef struct Rectangle {
    int width;
    int lenght;

} rectangle;


/************************
* Forward declarations
*************************/
int areaA(rectangle);
int areaB(struct Rectangle);
int areaC(rectangle*);
int areaD(const struct Rectangle*);
void rectangleInitialize(struct Rectangle*, int, int);
void changeRectangleLenght(struct Rectangle*, int);
void changeRectangleWidth(struct Rectangle*, int);

int main() {

    //Declared and initialized at load time
    struct Rectangle r1 = { 10, 20 };

    //Declated and unitialized
    struct Rectangle r2;

    //Call initializing function
    rectangleInitialize(&r2, 100, 20);
    
    int aa = areaA(r2);

    printf("areaA() %d\n", aa);

    int ab = areaB(r2);

    printf("areaB() %d\n", ab);

    int ac = areaC(&r2);

    printf("areaC() %d\n", ac);

    int ad = areaD(&r2);

    printf("areaD() %d\n", ad);

    changeRectangleLenght(&r2, 234);

    printf("r2 lenght changed to %d\n", r2.lenght);

    ad = areaD(&r2);

    printf("areaD() %d\n", ad);


}

/************************
* Function definitions 
*************************/

//Pass struct parameter by value
//i.e struct is copied to the areaA stack frame
//Changes will not be reflected in the original struct
int areaA(rectangle r) {

    r.width++;
    r.lenght++;

    return r.width * r.lenght;

}

//Pass user defined type Rectangle as a parameter
//Pass by value
//Changes will not be reflected in the original Rectangle
int areaB(struct Rectangle r) {

    return r.width * r.lenght;

}

//Pass struct by address (pointer)
int areaC(rectangle *r) {

    return r->width * r->lenght;

}

//Pass struct by address (pointer) and disallow modifications
int areaD(const struct Rectangle *r) {

    //r->lenght++; //W/ this line uncommented it won't compile
    return r->width * r->lenght;

}

void rectangleInitialize(struct Rectangle *r, int w, int l) {
    r->width = w;
    r->lenght = l;
}

void changeRectangleLenght(struct Rectangle *r, int l) {
    r->lenght = l;
}

void changeRectangleWidth(struct Rectangle *r, int w) {
    r->width = w;
}

