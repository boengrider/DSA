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

    static char string[] = { "ABC" };
    
   
    /**
    translate(string, LOWER);
    permutation(string, 0);
    **/


    printf("%d\n",factorial(5));
    printf("%d\n",factorial(6));
    printf("%d\n",factorial(7));

   

    return 0;
        

}

void permutation(char *string, int key)
{
    while(key != strlen(string))
    {
        return permutation(string, ++key);
        printf("Letter %c\n", string[key]);
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