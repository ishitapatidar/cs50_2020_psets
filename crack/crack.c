#include<stdio.h>
#include<string.h>
#include<cs50.h>
#define  _XOPEN_SOURCE
#include <unistd.h>
char *crypt(const char*key, const char*salt);
int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("usage: ./crack hash");
        return 1;
    }


    const char *hashed_word=NULL;
    const char *hash_given= argv[1];
    const char *salt= "50";

    char word[6];

    const char *alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // for 1 character
    for(int x=0;x<52;x++)
    {

        word[0]= alphabet[x];

        hashed_word= crypt(word,salt);

        if (strcmp(hash_given,hashed_word)==0)
        {
            goto P;
        }

    }

    //for 2 characters
    for(int x=0;x<52; x++)
    {
        word[0]= alphabet[x];
        for(int y=0;y<52; y++)
        {
            word[1]=alphabet[y];

            hashed_word=crypt(word,salt);
            if (strcmp(hashed_word,hash_given)==0)
            {
                goto P;
            }

        }
    }

    //for 3 characters
    for(int x=0; x<52 ; x++)
    {
        word[0]= alphabet[x];
        for(int y=0; y<52; y++)
        {
            word[1]= alphabet[y];
            for(int z=0; z<52 ; z++)
            {
                word[2]= alphabet[z];
                hashed_word= crypt(word,salt);
                if (strcmp(hashed_word,hash_given)==0)
                {
                    goto P;
                }
            }
        }
    }

    //for 4 characters
    for (int x=0;x<52; x++)
    {
        word[0]= alphabet[x];


        for(int y=0; y<52; y++)
        {
            word[1]= alphabet[y];
            for(int z=0; z<52; z++)
            {
                word[2]= alphabet[z];

                for(int a=0;a<52;a++)
                {
                    word[3]=alphabet[a];
                    hashed_word= crypt(word,salt);
                    if (strcmp(hashed_word,hash_given)==0)
                    {
                        goto P;
                    }
                }
            }

        }
    }

    //for 5 characters
    for(int x=0;x<52;x++)
    {
        word[0]= alphabet[x];
        for(int y=0;y<52;y++)
        {
            word[1]= alphabet[y];
            for(int z=0;z<52; z++)
            {
                word[2]= alphabet[z];
                for(int a=0;a<52;a++)
                {
                    word[3]= alphabet[a];
                    for(int b=0;b<52; b++)
                    {
                        word[4]= alphabet[b];
                        hashed_word= crypt(word,salt);
                        if (strcmp(hashed_word,hash_given)==0)
                        {
                            goto P;
                        }
                    }
                }
            }
        }
    }

    P: printf("%s \n", word);
    return 0;
}
