static int globalStaticVariable = 10;
static int globalStaticVariable2 = 50;
int globalVariable = 20;
static int foo();
int main() {
    int localStaticVariable = 30;

    int v = foo();
}


static int foo() {
    static int fooStatic = 40;
    return fooStatic;
}
