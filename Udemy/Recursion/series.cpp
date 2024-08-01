#include <iostream>
using namespace std;
void series(int);
void seriesReversed(int);

int main() {

    series(10);
    seriesReversed(10);

}


void series(int count) {

    if(count > 0) {
        cout << count << " ";
        series(count - 1);
    } else {
        cout << endl;
    }

}

void seriesReversed(int count) {

    if(count > 0) {
        seriesReversed(count - 1);
        cout << count << " ";
    } else {
        cout << endl;
    }
}