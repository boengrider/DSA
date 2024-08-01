#include <iostream>

using namespace std;

class myException : exception {
    public:
        string errorMessage = "Unkown error";
};

void mightGoWrong() {
    bool error = true;
    
    
    if(error) {
        throw myException();
    }
}

int main() {


    try
    {
        mightGoWrong();
    }
    catch(string e)
    {
        std::cerr << e << '\n';
    }
    catch(myException e) {
        std::cerr << e.errorMessage << endl;
    
    cout << "Recovery not possible. Exiting now ...." << endl;

    return 0;

    }

}
