#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

float sentence_count(string text);
float word_count(string text);
float letter_count(string text);

int main(void)
{
    string text = get_string("Text - ");

    float L = letter_count(text)/word_count(text)*100;
    float S = sentence_count(text)/word_count(text)*100;

    float formula = 0.0588*L - 0.296*S - 15.8;

    int index = round(formula);

    if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

float letter_count(string text)
{
    int count = 0;
    for (int i=0;text[i]!='\0';i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

float word_count(string text)
{
    int count = 0;
    for (int i=0;text[i]!='\0';i++)
    {
        if (text[i]==' ')
        {
            count++;
        }
    }
    return count+1;
}

float sentence_count(string text)
{
    int count=0;
    for(int i=0;text[i]!='\0';i++)
    {
        if (text[i]=='.'||text[i]=='?'||text[i]=='!')
        {
            count++;
        }
    }
    return count;
}