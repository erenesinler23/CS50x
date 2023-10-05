// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string word = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word \n");
        return 1;
    }
    else if (argc == 2)
    {
        for (int i = 0, n = strlen(word); i < n; i++)
        {
            if (word[i] == 'a')
            {
                word[i] = '6';
                printf("%c", word[i]);
            }
            else if (word[i] == 'e')
            {
                word[i] = '3';
                printf("%c", word[i]);
            }
            else if (word[i] == 'i')
            {
                word[i] = '1';
                printf("%c", word[i]);
            }
            else if (word[i] == 'o')
            {
                word[i] = '0';
                printf("%c", word[i]);
            }
            else
            {
                printf("%c", word[i]);
            }
        }
        printf("\n");
    }
}
