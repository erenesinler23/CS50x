#include "helpers.h"
#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Make sure the code doesn't pass 255.
int max(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaBlue;
    int sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = max(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            sepiaGreen = max(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaRed = max(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2;
             j++) // We divided to 2 because we want to swap half of the picture, or it will come back to normal!
        {
            /** Swap pixels from left to right */
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // We made temporarily to avoid modifying permenantly.

    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int column = 0; column < width; column++)
        {
            // Duplicate the original image
            temp[row][column] = image[row][column];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int averageRed = 0;
            int averageBlue = 0;
            int averageGreen = 0;

            float count = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (row + i < 0 || row + i >= height)
                    {
                        continue;
                    }
                    if (column + j < 0 || column + j >= width)
                    {
                        continue;
                    }
                    averageRed += temp[row + i][column + j].rgbtRed;
                    averageGreen += temp[row + i][column + j].rgbtGreen;
                    averageBlue += temp[row + i][column + j].rgbtBlue;

                    count++;
                }
            }

            image[row][column].rgbtRed = round(averageRed / count);
            image[row][column].rgbtBlue = round(averageBlue / count);
            image[row][column].rgbtGreen = round(averageGreen / count);
        }
    }
}

/*
The function grayscale should take an image and turn it into a black-and-white version of the same image.
The function sepia should take an image and turn it into a sepia version of the same image.
The reflect function should take an image and reflect it horizontally.
Finally, the blur function should take an image and turn it into a box-blurred version of the same image.

./filter -g INFILE.bmp OUTFILE.bmp
./filter -s INFILE.bmp OUTFILE.bmp
./filter -r INFILE.bmp OUTFILE.bmp
./filter -b INFILE.bmp OUTFILE.bmp
*/