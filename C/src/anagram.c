#include <stdio.h>
#include <string.h>

//lower letter 'a'
#define BOUNDARY 97

int isAnagram(char *wordA, char *wordB);
int isPalindrome(char *word);
void toLower(char *word);

int main()
{

    static char wordA[] = { "Decimall" };
    static char wordB[] = { "Medlical" };
    
   
    if(isAnagram(wordA,wordB))
    {
        printf("Words %s and %s are anagrams\n", wordA, wordB);
    } else {
        printf("Words %s and %s are not anagrams\n", wordA, wordB);
    }

   

    return 0;
        

}

void flipCase(char *word, unsigned long len)
{
    for(unsigned long i = 0; i < len; i++)
    {
        word[i] = word[i] ^ 32;
    }
}

int isAnagram(char *wordA, char *wordB)
{
    char map[26];

    //Check length
    if(strlen(wordA) != strlen(wordB))
        return 0;


    memset((void*)map, 0, sizeof(map));
    toLower(wordA);
    toLower(wordB);

    for(unsigned long i = 0; i < strlen(wordA); i++)
    {
        map[wordA[i] - BOUNDARY]++;
    }

    for(unsigned long i = 0; i < strlen(wordB); i++)
    {
        if((--map[wordB[i] - BOUNDARY]) < 0)
            return 0;
    }

    for(int i = 0; i < 26; i++)
    {
        if(map[i] != 0)
            return 0;
    }

    return 1;

}

int isPalindrome(char *word)
{

    int _isPalindrome;
    unsigned long i,j;
    j = strlen(word) - 1;
    _isPalindrome = i = 0;
    

    //translate to common case (lower) first
    //ASCII range [97-122]
    toLower(word);

    printf("Transaled word %s\n", word);
    printf("1st character is %c\nLast character is %c\n", word[i], word[j]);

    while(i < j)
    {
        //Both characters are letters
        if((word[i] >= 97 && word[i] <= 122) && (word[j] >= 97 && word[j] <= 122))
        {
            //But they do not match
            if(word[i] != word[j])
                return 0;
            
            //They match
            ++i;
            --j;
        }

        //Both characters are not letters
        if((word[i] < 97 || word[i] > 122) && (word[j] < 97 || word[j] > 122))
        {
            //Skip them
            ++i;
            --j;
        }

        //Character from the left is a letter but character from the right is not
        if((word[i] >= 97 && word[i] <= 122) && (word[j] < 97 || word[j] > 122))
        {
            //Ingore charcter from the right in this iteration
            --j;
        }

        //Character from the left is not a letter but character from the right is
        if((word[i] < 97 || word[i] > 122) && (word[j] >= 97 || word[j] <= 122))
        {
            //Ingore character from the left in this iteration
            ++i;
        }
    }


    return _isPalindrome = 1;
}

void toLower(char *word)
{
    unsigned long _len = strlen(word);

    for(unsigned long i = 0; i < _len; i++)
    {
        word[i] = word[i] | 32;
    }
}