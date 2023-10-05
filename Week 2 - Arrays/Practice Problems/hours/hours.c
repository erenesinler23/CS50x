#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float total;
float total_hour;
float divided;
float calc_hours(int hours[], int weeks, char output)
{
    if (output == 'T')
    {
        for (int j = 0; j < weeks; j++)
        {
            total += hours[j];
        }
    }
    else if (output == 'A')
    {
        for (int k = 0; k < weeks; k++)
        {
            total_hour += hours[k];
            total = (total_hour / weeks);
        }
    }
    return total;
}