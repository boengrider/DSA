#include <iostream>

using namespace std;



int main() {
    
    
   //1st lambda
   [](){
        int localValue = 10;
        cout << "I'm a lambda 1 " << localValue << endl;

        //2nd lambda
    [](){
        int localValue = 20;
        cout << "I'm a lambda 2 " << localValue << endl;
    }();
    }();

    


    

    

   

}

