#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

class FileException : public exception {
    public:
        FileException(int);
        virtual const char* what() const throw();
    private:
        int __errorCode;
};

FileException::FileException(int code) {
    this->__errorCode = code;
}

const char* FileException::what() const throw() {
    switch (this->__errorCode)
    {
    case 1:
        return "File create error";
        break;
    case 2:
        return "File not found";
        break;
    
    default:
        return "Uknown error";
        break;
    }
}


void writeTextFileA(string);
void writeTextFileB(const char*);

int main() {

    try
    {
        writeTextFileB("logX.txt");
    }
    catch(const FileException& e)
    {
        std::cout << "Excecption caught: ";
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    


}


void writeTextFileA(string _fileName) {
    ofstream __outFile;
    string __fileName = _fileName;
    
    __outFile.open(__fileName);

    if(__outFile.is_open()) {
        __outFile << "writeTextFileA";
        __outFile.close();
    } else {
        cout << "Couldn't open the file: " << __fileName << endl;
    }
}

void writeTextFileB(const char *_fileName) {
    int __fd = open(_fileName, O_WRONLY | O_APPEND);

    if(__fd < 0) {
        throw FileException(2);
        cout << "Does this run ?" << endl;
    }
    write(__fd, "Hello World", 11);
    fsync(__fd);
    close(__fd);
    

}

