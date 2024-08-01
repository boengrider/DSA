#include <list>
#include <iostream>
#include <string>

using namespace std;


typedef struct Rectangle {
    int length;
    int width;
} rectangle;

int area(rectangle);

int main() {

    const auto allocator = { 1, 2, 3};

    list<int> myList(allocator);


    cout << myList.size() << endl;

    myList.insert(myList.begin(), {4});


    for(const auto& item : myList) {
        cout << item << endl;
    }

    list<rectangle> rectangles = { {10,20}, {20,10}, {100,200}, {200,100} };


    for(const auto& rectangle : rectangles) {
        cout << "Rectangle area: " << area(rectangle) << endl;
    }
    
}

int area(rectangle r) {
    return r.length * r.width;
}