#include <stdio.h>

//Struct definition
struct Person {
    double age;
    double height;
    double weight;
}; 


//Pass by value
double calculateBmi(struct Person);

//Pass by address
double calculateBmi2(struct Person*);

//Pass by reference
double calculateBmi3(struct Person);

void modifyLocalParameterPassedByValue(struct Person);




int main() {

    struct Person p1 = {34.0, 183.0, 95.0};
    


    printf("Your BMI is %.1f\n", calculateBmi(p1));

    printf("Your BMI is %.1f\n", calculateBmi2(&p1));

    modifyLocalParameterPassedByValue(p1);

    printf("Original age %d\n", p1.age);

}

void modifyLocalParameterPassedByValue(struct Person p) {

    //Modifying p here will not have any effect on struct passed to the function
    p.age = 30.0;
    printf("Modified person's age %d\n", p.age);

}

double calculateBmi(struct Person p) {

    return ((double)p.weight / ((double)p.height * (double)p.height)) * 10000;

}

double calculateBmi2(struct Person *p) {
    return (p->weight / (p->height * p->height) * 10000);
}

