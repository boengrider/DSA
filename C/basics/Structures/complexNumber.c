#include <stdio.h>

struct Teacher {
    const char *name;
    int age;
};

char teacherA[] = { "Jon Doe" };
char teacherB[] = { "Jane Doe" };



int main() {

    struct Teacher teachers[2] = { {teacherA, 35}, {teacherB, 25}};

}
