#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //prompt user for text
    string text = "";
    do
    {
        text = get_string(" Text: ");
    }
    while (strcmp(text, "") == 0);

    //letters
    int letters = 0;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }

    //printf("letters : %d\n", letters);

    //words and sentences
    int words = 0;
    int sentences = 0;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //very last word
    words++;

    //printf(" words : %d\n", words);
    //printf(" sentences : %d\n", sentences);

    //readability grade
    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    int result = round(index);
    if (result > 16)
    {
        printf("Grade 16+\n");
    }

    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %d\n", result);
    }
}