#include <iostream>
#include <exception>

using namespace std;

void foo();
void bar();

int main() {
    /** 
     * The exception propagates outward until a viable handler is found. 
     * If the exception proceeds outward past main()
     * the default behavior is to terminate the program
     **/
    try
    {
        foo();
    }
    catch(const std::exception& e)
    {
        cout << "main() caught the exception: ";
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}


//foo() doesn't handle, so the exception
//propagates up the call stack
void foo() {
    bar();  
}

//bar() causes exception
void bar() {
    throw exception();
}
