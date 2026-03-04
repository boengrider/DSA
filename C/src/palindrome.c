#include <stdio.h>
#include <string.h>


void flipCase(char *word, unsigned long len);
int isPalindrome(char *word);
int main()
{

    static char word[] = { "saippuakivikauppias" };
    
    isPalindrome(word);
    unsigned long wordLen = strlen(word) - 1;

    //flipCase(word, wordLen);


   int isPalindrome = 1;
   

   for(int i = 0, j = wordLen; i < wordLen; i++, j--)
   {
        if(!(word[i] == word[j]))
        {
            isPalindrome = 0;
            break;
        }
   }

   if(isPalindrome)
        printf("Word %s is a palindrome\n", word);

   if(!isPalindrome)    
        printf("Word %s is not a palindrome\n", word);

}

void flipCase(char *word, unsigned long len)
{
    for(unsigned long i = 0; i < len; i++)
    {
        word[i] = word[i] ^ 32;
    }
}

int isPalindrome(char *word)
{
    int _isPalindrome = 0;
    unsigned long len = strlen(word);

    printf("Word %s of length %lu\n", word, len);
    printf("1st character is %c. Last character is %c\n", word[0], word[len-1]);

    int i,j;
    i = 0;
    j = len;

    while(i != j)
    {
        //From the left
        if((word[i] >= 65 || word[i] <= 90) || (word[i] >= 97 || word[i] <= 122))
        {
            //From the right
            if((word[j] >= 65 || word[j] <= 90) || (word[j] >= 97 || word[j] <= 122))
            {
                if(word[i] != word[j])
                    break; // Both are alphanumeric, but they differ. Not a palindrome
            }

            i++;
            j--;
        }
    }


}