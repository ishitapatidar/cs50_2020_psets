#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK 512



int main(int argc, char *argv[])
{
    // sanity check for command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    // open file
    FILE *fp = fopen(argv[1], "r");

    if (!fp)
    {
        printf("File doesn't open up or it doesn't exist \n");
        return 1;
    }

    // buffer
    unsigned char buffer[BLOCK];

    // jpeg count
    int count = 0;
    int jpeg_open = 0;

    // FILE POINTER FOR JPEG
    FILE *ptr = NULL;



    // till eof reached
    while (fread(buffer, BLOCK, 1, fp) == 1)
    {
        // look for a valid jpeg
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // if a jpeg file already open
            if (jpeg_open == 1)
            {
                fclose(ptr);

            }

            else
            {
                jpeg_open = 1;
            }

            // open file to store jpeg

            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            ptr = fopen(filename, "a");

            count++;


        }

        if (jpeg_open == 1)
        {
            fwrite(buffer, BLOCK, 1, ptr);
        }
    }
    fclose(fp);
    fclose(ptr);
    return 0;

}
