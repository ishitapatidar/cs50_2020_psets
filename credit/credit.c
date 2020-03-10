#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for user input
    long n ;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    //calculate checksum
    int count = 0;
    int digi = 0;
    int sum1 = 0;
    int sum2 = 0;
    //digi=254%10
    //number= number/10
    long number = n;
    while (number > 0)
    {
        count++;
        //extract digit
        digi = number % 10;
        //printf("digit %d\n", digi);
        //the remaining number
        number /= 10;

        //printf("number %ld\n", number);

        //sum1 calc
        if (count % 2 == 0)
        {
            //multiply digit by 2
            digi *= 2;

            //add product's digits to the sum
            while (digi != 0)
            {
                sum1 += (digi % 10);
                digi /= 10;
            }
            //printf("sum1 %d\n", sum1);
        }

        //sum2 calc
        else
        {
            sum2 += digi;

            //printf("sum2 %d\n", sum2);
        }
    }
    //printf("%d\n", sum1+sum2);
    //check last digit not 0
    if ((sum1 + sum2) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    else
    {
        //printf("count %d\n", count);
        //checksum validated
        //american express 15 digit, start with 34 or 37
        if ((count == 15) && (((n / (long)(pow(10.0, 13.0))) == 34) || ((n / (long)(pow(10.0, 13.0))) == 37)))
        {
            printf("AMEX\n");
        }

        //mastercard 16 digit, start with 51,52,53,54,55
        else if (count == 16)
        {
            //first 2 digits
            int start = n / ((long)(pow(10.0, 14.0)));
            //printf("start %d\n", start);

            if ((start == 51) || (start == 52) || (start == 53) || (start == 54) || (start == 55))
            {
                printf("MASTERCARD\n");
            }

            else if (start / 10 == 4)
            {
                printf("VISA\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else if (count == 13)
        {
            if ((n / (long)(pow(10.0, 12.0))) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVAID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }

        return 0;

    }

}







