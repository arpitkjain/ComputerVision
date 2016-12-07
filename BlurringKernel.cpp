/*
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
Mat BlurImage(Image.rows, Image.cols, CV_8UC1);


int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}

void BlurBulk(int z, void* dummy)
{
	int sumx;
	z = 2 * z + 1;
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			sumx = 0;
			int counter = 0;
			for (int k = i - z/2; k < i + z/2 +1; k++)
			{
				for (int m = j - z/2; m < j + z/2 +1; m++)
				{
					if (isvalid(k, m))
					{
						counter++;
						sumx += Image.at<uchar>(k, m);
					}
				}
			}
			BlurImage.at<uchar>(i, j) = sumx / counter;
		}
	}


	imshow("Blur", BlurImage);
}

int main()
{
	int z = 0;
	BlurBulk(z,0);
	
	namedWindow("Blur", CV_WINDOW_AUTOSIZE);
	createTrackbar("Size:", "Blur", &z, 5, BlurBulk, 0);


	imshow("Image", Image);
	waitKey(0);
	getchar();
	return 0;
}
*/