#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class Arithmetic {
    private:
        T a;  
        T b;

    public:
        Arithmetic(T, T);
        T add();
        T sub();
};


//Implementation of Arithmetic class
template<class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

//This also works
/**
Arithmetic::Arithmetic(int a, int b) {
    Arithmetic::a = a;
    Arithmetic::b = b;
}
**/

template<class T>
T Arithmetic<T>::add() {
    return a + b;
}

template<class T>
T Arithmetic<T>::sub() {
    return a - b;
}

struct Entry {
    string name;
    int number;

};



int main() {
    Arithmetic<int> i(10, 20);

    cout << i.add() << endl;
    cout << i.sub() << endl;

    Arithmetic<float> f(10.1, 20.7);

    cout << f.add() << endl;
    cout << f.sub() << endl;

    vector<Entry> PhoneBook = {{"Jon Doe", 123},
                               {"Jane Doe", 456}};

    cout << "Number of entries -> " << PhoneBook.size() << endl;

    cout << "Adding 'Michael J. Scott' to the phone book" << endl;

    PhoneBook.insert(PhoneBook.begin() + PhoneBook.size(), { "Michael J. Scott", 555});

    cout << "Number of entries -> " << PhoneBook.size() << endl;

    cout << "Last entry added -> " << PhoneBook[PhoneBook.size() - 1].name << endl;

    



    

    

    
    
}