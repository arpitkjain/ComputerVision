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

void BlurBulk()
{
	int sumx;

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			sumx = 0;
			int counter = 0;
			int arr[9];
			for (int k = i - 1; k < i + 2; k++)
			{
				for (int m = j - 1; m < j + 2; m++)
				{
					if (isvalid(k, m))
					{
						arr[counter] = Image.at<uchar>(k, m);
						counter++;
					}
				}
			}
			sort(arr,arr+counter-1);

			BlurImage.at<uchar>(i, j) = arr[counter/2];
		}
	}
}

int main()
{
	BlurBulk();
	imshow("Image", Image);
	imshow("Blur", BlurImage);
	waitKey(0);
	getchar();
	return 0;
}
*/