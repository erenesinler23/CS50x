#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {

        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        for (int s = 0; s < i; s++)
        {
            printf("#");
        }
        printf("\n");
    }
}