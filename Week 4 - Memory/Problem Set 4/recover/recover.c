#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

//  In the provided C code, buffer is an array of uint8_t (bytes) used to read blocks of data from the input file.

int main(int argc, char *argv[])
{
    // To check if command line argument written, proper usage
    if (argc != 2)
    {
        printf("Usage ./recover filename.raw\n");
        return 1;
    }

    // Open memory card
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Creating a buffer - Pointer to store the real data as explained above.
    typedef uint8_t byte;
    byte buffer[BLOCK_SIZE];

    // Counts the number of JPEG found
    int count = 0;

    // Allocating memory for the name.
    char *filename = malloc(8 * sizeof(char));

    // Output defined
    FILE *output = NULL;

    // Loop in the whole data and read
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Is there a JPEG found?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // First JPEG found
            if (count == 0)
            {
                // Write the file
                sprintf(filename, "%03i.jpg", count);
                //Sprintf is for string printf, it stores the result in arrray(string)
                output = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, output);

                count++;
            }
            // Already found JPEG
            else if (count > 0)
            {
                fclose(output);
                sprintf(filename, "%03i.jpg", count);
                output = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, output);

                count++;
            }
        }
        // Not a new JPEG
        else if (count > 0)
        {
            // Keep writing
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }
    // Free used storage and close the files
    free(filename);
    fclose(file);
    fclose(output);
}