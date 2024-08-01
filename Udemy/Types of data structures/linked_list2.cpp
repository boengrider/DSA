#include <list>
#include <iostream>

using namespace std;




int main() {

    list<int> numbers = {8, 3, 9, 4, 6, 10, 12};

    numbers.sort();

    for(const auto& item : numbers) {
        cout << item << ", ";
    };
    cout << endl;

    
}

