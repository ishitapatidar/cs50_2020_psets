#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int c=0;
    // c is for coin count

    float n;
    //n is for the chnage owed

    //prompting the user to enter the change owed
    do
    {
        n= get_float("hello there! please enter the change owed in dollars: ");

    }
    while(n<=0);

    //calculating the minimum number of changes
    //converting dollars to cents
    n = round(n*100);

    //number of quaters.
    while (n>=25)
    {

        n-=25;
        c++;
    }

    //number of dimes
    while (n>=10)
    {

        n-=10;
        c++;
    }

    //number of nickles
    while (n>=5)
    {

        n-=5;
        c++;
    }

    //number of pennies
    while (n>=1)
    {

        n-=1;
        c++;

    }
    printf("%i\n",c);

}