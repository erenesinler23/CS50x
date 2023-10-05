#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
        // wrong equals to returning 1
    }
    {
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            // tmp means temporarily
            char tmp = argv[1][i];
            // checks the every element / character in the first argument
            if (!isdigit(tmp))
            // checks if its a digit
            {
                printf("Usage: ./caesar key\n");
                return 1;
                // Wrong equals to returning 1
            }
        }
    }
    // atoi means ascii to integer converter
    int key = atoi(argv[1]);

    // Getting input
    string plain_text = get_string("Plain text: ");

    printf("Ciphertext: ");

    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        if (isalpha(plain_text[i]))
        {
            if (isupper(plain_text[i]))
            // this is for capital plain texts, converting them
            {
                char cipher_capital = ((plain_text[i] - 65 + key) % 26) + 65;
                printf("%c", cipher_capital);
            }

            if (islower(plain_text[i]))
            {
                char cipher_lower = ((plain_text[i] - 97 + key) % 26) + 97;
                printf("%c", cipher_lower);
                // this is for lower plain texts, converting them
            }
        }
        else
        {
            printf("%c", plain_text[i]);
            // this is for non characters such as !, ? and space and many more. 
        }
    }

    printf("\n");
    return 0;
}