#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{   //GETTING KEY
    if(argc!=2)
    {
        printf("usage: ./caesar  k\n");
        return 1;
    }
    int key= atoi(argv[1]);

    //GETTING PLAINTEXT
    string plaintext;

    plaintext= get_string("plaintext: ");



    //PRESERVING CASE AND ENCIPHERING
    printf("ciphertext: ");
    for(int i=0, n=strlen(plaintext); i<n; i++)
    {


        if (isupper(plaintext[i]))
        {
            printf("%c",((plaintext[i]-'A'+key)%26+'A'));
        }
        else if(islower(plaintext[i]))
        {
            printf("%c",((plaintext[i]-'a'+key)%26+'a'));
        }



        else
        {
            printf("%c",plaintext[i]);
        }

    }
    printf("\n");

}