#include <iostream>

using namespace std;

int main() {
    
    
    
   /** 
   //1st lambda
   //Anonymous
   //No params
   //No captures
   [](){
        int localValue = 10;
        cout << "I'm a lambda 1 " << localValue << endl;

    }();
    **/


   //2nd lambda
   //Anonymous
   //Takes 2 params 
   //Has 2 captures
   int retval = 
   [](int p1, int p2)->int{
        return p1 + p2;
   }(7,3);

   cout << retval << endl;


   int a = 7;
   int b = 3;

   [a,b](){
        cout << a << endl;
        cout << b << endl;
   }();


   /** Function vs Lambda and enclosing scope
    *  Define a lambda that captures a variable on the main()'s stack frame
    * */

   //
   int mainStackVariable = 10;

   for(int i = 0; i < 10; ++i) {
    cout << "Outer value of 'mainStackVariable' -> " << mainStackVariable << endl;
    mainStackVariable++;
    [mainStackVariable](){
        cout << "Inner value of 'mainStackVariable -> " << mainStackVariable << endl;
    }();
   }

   
} 
    
   