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

float GaussMat[3][3] = { { 1.0 / 16.0, 1.0/ 8.0, 1.0/ 16.0 }, { 1.0/ 8.0, 1.0 / 4.0, 1.0 / 8.0 }, { 1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0 } };

int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}


float MultiplyWithGauss(int k, int m)
{
	float sumx=0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isvalid(k-1+i, m-1+j))
			{
				sumx += GaussMat[i][j] * (float)Image.at<uchar>(k-1+i, m-1+j);
			}
			
		}
	}
	return sumx;
}


void BlurBulk()
{

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			BlurImage.at<uchar>(i, j) = (int)MultiplyWithGauss(i, j);
		}
	}
}


int main()
{
	BlurBulk();
	imshow("Image", Image);
	imshow("Blur", BlurImage);
	Compare();
	waitKey(0);
	return 0;
}
*/