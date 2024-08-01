#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Entry {
    string name;
    int number;
};

//prototype
void print_book(const vector<Entry> &);

int main() {
    
    vector<Entry> phone_bookA = {
        {"Michael J. Scott", 555},
        {"Dwight K. Schrute", 666}
    };

    vector<Entry> phone_bookB = {
        {"Jim Halpert", 111},
        {"Stanley Hudson", 222}
    };


    print_book(phone_bookA);

    phone_bookA.swap(phone_bookB);

    print_book(phone_bookA);

    cout << "Capacity " << phone_bookA.capacity() << endl;
    cout << phone_bookA.begin().
  

}

void print_book(const vector<Entry> &book) {
    for(int i = 0; i != book.size(); ++i) {
        cout << book.at(i).name << " " << book.at(i).number << endl;
    }
}


