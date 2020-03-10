#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    //prompting user to enter a positive no.
    do
    {
        h = get_int(" enter a positive number less than 23: ");

    }
    while (h<0 || h>23);

    //handling height of 0
    if (h==0)
        return 0;

    //making the pattern


    for (int i=h ; i>0 ; i--)
    {
        for (int j=(i-1); j>0; j--)
        {
            printf(" ");

        }
        for (int k=0; k<(h+2-i) ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}