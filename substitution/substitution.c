#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    //get key
    //validate key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checking for 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters \n");
        return 1;
    }


    int i = 0;
    int n = strlen(argv[1]);

    while (i < n)
    {
        //checking for non alphabetic character apperance
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must  only contain alphabetic characters\n");
            return 1;
        }


        //checking for repeated character occurence
        for (int j = i + 1 ; j < n ; j++)
        {
            //ignore case
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
        i++;
    }

    //get plaintext
    string plain = "";
    do
    {
        plain = get_string("Plaintext: ");
    }
    while (strcmp(plain, "") == 0);



    //encrypt
    int m = strlen(plain);
    char cipher[m];
    int index = 0;
    for (int k = 0 ; k < m ; k ++)
    {
        //find index

        if (isalpha(plain[k]) != 0)
        {

            index = islower(plain[k]) != 0 ? plain[k] - 'a' : plain[k] - 'A';
            cipher[k] = islower(plain[k]) != 0 ? tolower(argv[1][index]) : toupper(argv[1][index]);
        }

        else
        {
            cipher[k] = plain[k];
        }
    }

    //print ciphertext
    printf("ciphertext: ");
    for (int k = 0 ; k < m ; k++)
    {
        printf("%c", cipher[k]);
    }
    printf("\n");
    return 0;

}



