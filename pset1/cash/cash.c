#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents,coins,quarters,dimes,nickels,pennies;
    quarters = dimes = nickels = pennies = 0;

    cents = get_cents(cents);
    quarters = calculate_quarters(cents);
    cents -= quarters*25;
    dimes = calculate_dimes(cents);
    cents -= dimes*10;
    nickels = calculate_nickels(cents);
    cents -= nickels*5;
    pennies = calculate_pennies(cents);
    cents -= pennies*1;



    // Sum coins
    coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}


int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Cash owed - ");
    }
    while (cents<0 || cents>100);
    return cents;
}

void calculate_quarters(int cents)
{
    int quarters = 0;
     while(cents)
    {
        if(cents >= 25)
        {
            quarters++;
            cents -= 25;
        }
    }
    return 0;
}

void calculate_dimes(int cents)
{
    int dimes = 0;
    while(cents)
    {
        if (cents >= 10)
        {
            dimes++;
            cents -= 10;
        }
    }
    return 0;
}

void calculate_nickels(int cents)
{
    int nickels = 0;
    while(cents)
    {
        if (cents >= 5)
        {
            nickels++;
            cents -= 5;
        }
    }
    return 0;
}

void calculate_pennies(int cents)
{
    int pennies = 0;
    while(cents)
    {
        if(cents<5)
        {
            pennies++;
            cents--;
        }

    }
    return 0;
}