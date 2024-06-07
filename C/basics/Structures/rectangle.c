//Definition of a Rectangle struct. Only as an aid to the compiler. Produces no code
struct Rectangle {
    int length;
    int height;
};

int main() {

    //Uninitialized. Will be skipped by the compiler
    struct Rectangle r;

    //Initialized Rectangle struct on the main's stack
    struct Rectangle r2 = {10, 5};

}