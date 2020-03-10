#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{   //GETTING KEY
    if(argc!=2)
    {
        printf("usage: ./vigenere  k\n");
        return 1;
    }
    string key = argv[1];
    for ( int i=0, n=strlen(key); i<n ; i++)
    {
        if (isalpha(key[i])==0)
        {
            printf("usage: ./vigenere k");
            return 1;
        }
    }

    //GETTING PLAINTEXT
    string plaintext;

    plaintext= get_string("plaintext: ");



    //PRESERVING CASE AND ENCIPHERING
    printf("ciphertext: ");
    int j=0;
    for(int i=0, n=strlen(plaintext); i<n; i++)
    {
        j = j % strlen(key);

        if (isalpha(plaintext[i]))
        {

            if (isupper(plaintext[i]) && isupper(key[j]))
            {
                printf("%c",(((plaintext[i]-'A')+(key[j] -'A'))%26+'A'));
            }
            else if (islower(plaintext[i]) && islower(key[j]))
            {
                printf("%c",(((plaintext[i])-'a'+(key[j] - 'a'))%26+'a'));
            }
            else if(isupper(plaintext[i]) && islower(key[j]))
            {
                printf("%c",(((plaintext[i])-'A'+(key[j] - 'a'))%26+'A'));
            }

            else if( islower(plaintext[i]) && isupper(key[j]))
            {
                printf("%c",(((plaintext[i])-'a'+(key[j] - 'A'))%26+'a'));
            }
            j++;
        }


        else
        {
            printf("%c",plaintext[i]);
        }

    }
    printf("\n");
    return  0;

}