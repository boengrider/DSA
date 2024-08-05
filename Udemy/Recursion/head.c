#include <stdio.h>

void tail(int);
void head(int);


int main() {
    

    printf("Tail -> ");
    tail(10);

    printf("Head -> ");
    head(10);
  
   
}


//Prints sequence starting from 'n' to 1
void tail(int n) {

    if(n > 0) {
        printf("%d ", n);
        tail(n - 1);   
    } else {
        printf("\n");
    }

}

//Prints the sequence starting from 1 to 'n'
//Definition is almost identical to the tail()
//except for the order of printf() call 
//and the head() recursive call
//Also, there is no else clause 
//otherwise it would print a new line
//first instead of printing 1
void head(int n) {

    if(n > 0) {
        head(n - 1);
        printf("%d ", n);
    }
}
