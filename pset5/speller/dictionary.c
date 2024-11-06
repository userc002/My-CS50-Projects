// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

#include "dictionary.h"

unsigned int wordlen,hashval;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hashval= hash(word);
    node *p= table[hashval];

    while(p!= 0)
    {
        if(strcasecmp(word, p->word)== 0)
        {
            return true;
        }
        p= p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';

    unsigned long total= 0;

    for(int i= 0; i<strlen(word); i++)
    {
        total+= tolower(word[i]);
    }

    return total% N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *file= fopen(dictionary, "r");

    if(file== NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }

    char word[LENGTH+1];

    while(fscanf(file, "%s", word)!= EOF)
    {
        node *n= malloc(sizeof(node));

        if(n== NULL)
        {
            return false;
        }

        strcpy(n-> word, word);
        hashval= hash(word);
        n->next= table[hashval];
        table[hashval]= n;
        wordlen++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(wordlen>0)
    {
        return wordlen;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int j=0; j<N; j++)
    {
        node *p= table[j];

        while(p)
        {
            node *temp= p;
            p= p->next;
            free(temp);
        }

        if(p== NULL)
        {
            return true;
        }
    }
    return false;
}
