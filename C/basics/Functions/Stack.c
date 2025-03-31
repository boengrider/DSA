#include <stdio.h>

void foo(char*);
void bar(char*,char*, int);

int main() {

    char *name = "jon doe";

    foo(name);
}

void foo(char *p) {

    char buffer[20];
    bar(p, &buffer[0], 8);

    buffer[19] = '\0';

    printf("%s\n", buffer);

}

void bar(char *input, char *buffer, int sizeInput) {

    int offset = 32;

    for(int i = 0; i < sizeInput - 1; i++) {
        *(buffer + i) = *(input + 1) + offset;
    }


}