#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // for rows
    {
        for (int j = 0; j < width; j++) // for columns
        {
            if (image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0x80;
                image[i][j].rgbtBlue = 0x80;
                image[i][j].rgbtBlue = 0x00;
            }
        }
    }
}