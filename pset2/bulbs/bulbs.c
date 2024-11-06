#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO - Input and char to decimal to binary conversion

    string input = get_string("Message - ");
    int length = strlen(input);
    int binary[] = {0,0,0,0,0,0,0,0};

    for(int i=0; i<length; i++)
    {
        int count=0;
        int ascii = input[i];

        while(ascii>0)
        {
            binary[count]= ascii%2;
            ascii /=2;
            count++;
        }

        for(int k=BITS-1; k>=0; k--)
        {
            print_bulb(binary[k]);
        }

        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
