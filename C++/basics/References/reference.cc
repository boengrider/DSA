#include <iostream>

using namespace std;

int main() {

    int a = 10;

    int &r = a;

    std::cout << r << std::endl;

    std::cout << "Hello" << std::endl;
}