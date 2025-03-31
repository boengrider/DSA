#include <stdio.h>

#pragma pack(push, 1)
struct PersonA {
    char *name;
    int age;
};
#pragma pack(pop)

struct PersonB {
    char *name;
    int age;
};

void before_start_main(void);
void before_exit_main(void);

//won't work on GCC
//#pragma startup before_start_main()
//#pragma exit before_exit_main()

void __attribute__((constructor)) before_start_main();
void __attribute__((destructor)) before_exit_main();

int main() {
    printf("Inside main()\n");

    struct PersonA pa = {"Jon Does", 35};

    printf("Person %s age %d\n", pa.name, pa.age);

    printf("Size of PersonA is %d\n", sizeof(struct PersonA));

    printf("Size of PersonB is %d\n", sizeof(struct PersonB));
}


void before_start_main() {
    printf("This runs before controll is passed to the main function\n");
}

void before_exit_main() {
    printf("This runs before controll leaves the main function\n");
}