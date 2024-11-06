#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r=0; r<width; r++)
    {
        for (int c=0; c<height; c++)
        {
            double grayscale= round((image[c][r].rgbtRed +image[c][r].rgbtGreen +image[c][r].rgbtBlue)/3);
            image[c][r].rgbtRed= grayscale;
            image[c][r].rgbtGreen= grayscale;
            image[c][r].rgbtBlue= grayscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r=0; r<width; r++)
    {
        for (int c=0; c<height; c++)
        {
            float sred, sgreen, sblue;
            sred= round((0.393*image[c][r].rgbtRed)+ (0.769*image[c][r].rgbtGreen)+ (0.189*image[c][r].rgbtBlue));
            sgreen= round((0.349*image[c][r].rgbtRed)+ (0.686*image[c][r].rgbtGreen)+ (0.168*image[c][r].rgbtBlue));
            sblue= round((0.272*image[c][r].rgbtRed)+ (0.534*image[c][r].rgbtGreen)+ (0.131*image[c][r].rgbtBlue));

            if (sred> 255)
            {
                sred= 255;
            }
            else if (sgreen> 255)
            {
                sgreen= 255;
            }
            else if (sblue> 255)
            {
                sblue= 255;
            }

            image[c][r].rgbtRed= sred;
            image[c][r].rgbtGreen= sgreen;
            image[c][r].rgbtBlue= sblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int c=0; c<height; c++)
    {
        if (width%2 ==0)
        {
            for (int r=0; r< width/2; r++)
            {
                RGBTRIPLE temp[height][width];
                temp[c][r]= image[c][r];
                image[c][r]= image[c][width- (r+1)];
                image[c][width- (r+1)]= temp[c][r];
            }
        }
        else if (width%2 !=0)
        {
            for (int r=0; r< (width- 1)/2; r++)
            {
                RGBTRIPLE temp[height][width];
                temp[c][r]= image[c][r];
                image[c][r]= image[c][width- (r+1)];
                image[c][width- (r+1)]= temp[c][r];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int r=0; r<width; r++)
    {
        for (int c=0; c<height; c++)
        {
            temp[c][r]= image[c][r];
        }
    }

    for (int r=0; r<width; r++)
    {
        for (int c=0; c<height; c++)
        {
            int tred=0;
            int tblue=0;
            int tgreen=0;
            double count= 0;

            for (int x= -1; x<2; x++)
            {
                for (int y= -1; y<2; y++)
                {
                    int cx= c+x;
                    int cy= r+y;

                    if (cx< 0|| cx> (height- 1)|| cy< 0|| cy> (width- 1))
                    {
                        continue;
                    }

                    tred += image[cx][cy].rgbtRed;
                    tgreen += image[cx][cy].rgbtGreen;
                    tblue += image[cx][cy].rgbtBlue;

                    count++;
                }

                temp[c][r].rgbtRed= round(tred/count);
                temp[c][r].rgbtGreen= round(tgreen/count);
                temp[c][r].rgbtBlue= round(tblue/count);
            }
        }
    }

    for (int r=0; r<width; r++)
    {
        for (int c=0; c<height; c++)
        {
            image[c][r].rgbtRed= temp[c][r].rgbtRed;
            image[c][r].rgbtGreen= temp[c][r].rgbtGreen;
            image[c][r].rgbtBlue= temp[c][r].rgbtBlue;
        }
    }
    return;
}
