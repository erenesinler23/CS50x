#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string input = get_string("Text: ");

    int letters = count_letters(input);
    int sentences = count_sentences(input);
    int words = count_words(input);

    float L = (letters / (float) words) * 100;
    float S = ((float) sentences / words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(string text)
{
    int total_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Also, 46 is for '.' , 63 is for '?' and 33 is for '!'
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            total_sentences++;
        }
    }
    return total_sentences;
}

int count_letters(string text)
{
    int total_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // 97 is 'a' and 122 is 'z' while 65 is 'A' and 90 is 'Z'
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            total_letters++;
        }
    }
    return total_letters;
}

int count_words(string text)
{
    int total_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        // 32 is ' '
        if (text[i] == 32)
        {
            total_words++;
        }
    }
    return total_words;
}
