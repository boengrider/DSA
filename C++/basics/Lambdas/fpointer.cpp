int foo();
int main() {


    int (*p)() = foo;


}

int foo() {
    return 10;
}