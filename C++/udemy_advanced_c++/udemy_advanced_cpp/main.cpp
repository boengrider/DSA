#include <fstream>
#include <thread>
#include <chrono>
#include <ostream>
#include <iostream>

using namespace std;

using namespace chrono;

int main()
{


    cout << "abc";

    this_thread::sleep_for(1000ms);

    cout.seekp(1);

    cout << "d";

    string answer;

    cin >> answer;


}
