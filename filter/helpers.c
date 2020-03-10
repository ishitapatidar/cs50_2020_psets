#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (((float)image[i][j].rgbtBlue) + ((float)image[i][j].rgbtGreen) + ((float)image[i][j].rgbtRed)) / 3;
            image[i][j].rgbtBlue = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtRed = round(avg);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int mid = width / 2;
        int j = 0;
        while (j < mid)
        {
            // swapping values
            RGBTRIPLE temp = image[i][width - 1 - j];
            image[i][width - 1 - j] = image[i][j];
            image[i][j] = temp;

            j++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creating copy of image
    RGBTRIPLE copy[height][width];
    for (int m = 0 ; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            copy[m][n] = image[m][n];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // neighbouring pixels
            int ravg = 0, bavg = 0, gavg = 0, k, l, count = 0;
            // newighbourng rows
            for (k = i - 1; k <= i + 1; k++)
            {
                if (k >= 0 && k < height)
                {
                    //neighbouring columns
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (l >= 0 && l < width)
                        {
                            ravg += image[k][l].rgbtRed;
                            bavg += image[k][l].rgbtBlue;
                            gavg += image[k][l].rgbtGreen;
                            count++;
                        }

                    }

                }

            }

            // changing pixel of copy
            copy[i][j].rgbtRed = round((float)ravg / (float)count);
            copy[i][j].rgbtGreen = round((float)gavg / (float)count);
            copy[i][j].rgbtBlue = round((float)bavg / (float)count);

        }
    }

    // making changes in final image
    for (int m = 0 ; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            image[m][n] = copy[m][n];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gxa[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gya[3][3] = {{-1, -2, -1}, { 0, 0, 0}, { 1, 2, 1}};

    // creating copy of the image
    RGBTRIPLE copy[height][width];
    for (int m = 0 ; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            copy[m][n] = image [m][n];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int k, l, rGx = 0, rGy = 0, bGx = 0, bGy = 0, gGx = 0, gGy = 0, x = 0, y = 0;

            // performing box blur
            for (k = i - 1, x = 0; k <= i + 1 && x < 3; k++, x++)
            {
                if (k >= 0 && k < height)
                {

                    for (l = j - 1, y = 0; l <= j + 1 && y < 3; l++, y++)
                    {
                        if (l >= 0 && l < height)
                        {

                            rGx += (image[k][l].rgbtRed * gxa[x][y]);
                            gGx += image[k][l].rgbtGreen * gxa[x][y];
                            bGx += image[k][l].rgbtBlue * gxa[x][y];

                            rGy += image[k][l].rgbtRed * gya[x][y];
                            gGy += image[k][l].rgbtGreen * gya[x][y];
                            bGy += image[k][l].rgbtBlue * gya[x][y];

                        }
                        else
                        {
                            continue;
                        }
                    }

                }
                else
                {
                    continue;
                }

            }

            // sobel operator
            int red = round(sqrt((pow((double)rGx, 2.0)) + (pow((double)rGy, 2.0))));
            int green = round(sqrt((pow((double)gGx, 2.0)) + (pow((double)gGy, 2.0))));
            int blue = round(sqrt((pow((double)bGx, 2.0)) + (pow((double)bGy, 2.0))));

            //copying back to image
            copy[i][j].rgbtRed = (red > 255) ? 255 : red;
            copy[i][j].rgbtGreen = (green > 255) ? 255 : green;
            copy[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }

    }

    for (int m = 0 ; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            image[m][n] = copy[m][n];
        }
    }

    return;
}
