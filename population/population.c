#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size

    int startpop;
    do
    {
        startpop = get_int("Enter the starting population - ");
    }
    while (startpop<9);

    // Prompt for end size

    int endpop;
    do
    {
        endpop = get_int("Enter the ending population - ");
    }
    while (endpop<startpop);

    // Calculate number of years until we reach threshold

    int years = 0;
    while (startpop < endpop)
    {
        startpop = startpop + (startpop/3) - (startpop/4);
        years += 1;
    }


    // Print number of years

    printf("Years: %i\n",years);
}
