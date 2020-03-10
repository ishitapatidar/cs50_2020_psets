#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    //prompting the user to enter positive no.

    do
    {
        h = get_int("enter a positive number less than 23");

    }
    while(h<0 || h>23);

    //handling height of 0
    if (h==0)
        return 0;

    //creating pattern

    for(int i=0; i<h; i++)
    {
        //loop to handle spaces
        for(int j=(h-i-1); j>0 ; j--)
        {
            printf(" ");
        }

        //loop to handle symbol
        for(int k=0; k<i+1; k++)
        {
            printf("#");

        }
        printf("  ");
        for(int k=0; k<i+1; k++)
        {
            printf("#");

        }
        printf("\n");

    }
}