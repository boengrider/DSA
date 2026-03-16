//String permutations using recursion
#include <stdio.h>
#include <string.h>



typedef enum 
{
    LOWER,
    UPPER,
} Case;

void translate(char *word, Case c);
void permutation(char *string, int key);
int factorial(int n);

int main()
{

    char string[] = { "ABC" };
    permutation(string,0);
   

    /**
    translate(string, LOWER);
    permutation(string, 0);
    **/


   
   

    return 0;
        

}

void permutation(char *string, int key)
{

    char *__string = string;
    static char result[10];
    static char is_taken[10];

    for(int i = 0;; i++)
    {
        if(string[i] != '\0') 
        {
            printf("Current char is %c\n", string[i]);
            if(is_taken[i] == 0)
            {        
                printf("Character is not taken. Copying to result[]\n");
                result[i] = string[i];
            } 
        } else 
        {
            printf("Possible permutation of ABC: %s\n", result);
            break;
        }
        //permutation(__string, key - 1);
    }


    
}

int factorial(int n) 
{
    if(n == 1)
        return n;
    
    return n * factorial(n - 1);
}



void translate(char *word, Case c)
{
    unsigned long _len = strlen(word);

    if(c == LOWER)
    {
        for(unsigned long i = 0; i < _len; i++)
        {
            word[i] = word[i] | 32;
        }
    }

    if(c == UPPER)
    {
        for(unsigned long i = 0; i < _len; i++)
        {
            word[i] = word[i] ^ 32;
        }
    }
}