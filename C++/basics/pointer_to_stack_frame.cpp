#include <linux/limits.h>

void* foo();

int main() {
    
    void *allocatedSpace = foo();

}


void* foo() {
    void *p = new char[PATH_MAX];
}