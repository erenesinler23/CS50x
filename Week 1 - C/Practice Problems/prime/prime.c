#include <cs50.h>
#include <stdio.h>

bool is_prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (is_prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool is_prime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int divisor = 2; divisor * divisor <= number; divisor++)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }

    return true;
}