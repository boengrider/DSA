#include <iostream>

using namespace std;


int main() {
    int *p = new int[10];

    for(int i=0; i<10;++i) {
        p[i] = i + 1;
    }

    int *q = new int[20];

    for(int i=0; i<10;++i) {
        q[i] = p[i];
    }

    //See the contents
    for(int i=0; i<20;++i) {
        cout << q[i] << endl;
    }

    //Delete the original array
    delete p;
    p=q;
    q=nullptr;
}