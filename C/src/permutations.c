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
    static char taken[10];

    //Start with key 0, first character (A)
    for(int i = key;; i++)
    {
        if(!taken[i])
        {
            //Copy available letter to the result array
            result[i] = string[i];
            permutation(string, key + 1);
        }

        if(string[i] == '\0')
            break;
    }


    printf("%s\n", result);
    permutation(string, 1);
    

    
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