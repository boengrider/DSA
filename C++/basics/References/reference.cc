#include <iostream>

using namespace std;
int main() {

    int a = 10;

    int &r = a;

    std::cout << a << std::endl;


    r = 20;

    std::cout << a << std::endl;
}
