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
Mat BlurImageX(Image.rows, Image.cols, CV_8UC1);
Mat BlurImageY(Image.rows, Image.cols, CV_8UC1);
Mat Diagonal(Image.rows, Image.cols, CV_8UC1);
Mat DiagonalAngle(Image.rows, Image.cols, CV_8UC1);

float GaussMat[3][3] = { { -3, 0, 3 }, { -10, 0, 10 }, { -3, 0, 3 } };

int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}


float Gx(int k, int m)
{
	float sumx = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isvalid(k - 1 + i, m - 1 + j))
			{
				sumx += GaussMat[i][j] * (float)Image.at<uchar>(k - 1 + i, m - 1 + j);
			}

		}
	}
	return abs(sumx);
}

float Gy(int k, int m)
{
	float sumx = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isvalid(k - 1 + i, m - 1 + j))
			{
				sumx += GaussMat[j][i] * (float)Image.at<uchar>(k - 1 + i, m - 1 + j);
			}

		}
	}
	return abs(sumx);
}

void Gxy()
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			Diagonal.at<uchar>(i, j) = hypot(BlurImageX.at<uchar>(i, j), BlurImageY.at<uchar>(i, j));
			Diagonal.at<uchar>(i, j) = Diagonal.at<uchar>(i, j)>120 ? 255 : 0;
		}
	}
	imshow("Diagonal", Diagonal);
}

void Gtheta()
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			DiagonalAngle.at<uchar>(i, j) = atan2(BlurImageY.at<uchar>(i, j), BlurImageX.at<uchar>(i, j))*127.0 / 1.57;
		}
	}
	imshow("DiagonalAngle", DiagonalAngle);
}

void BlurBulk()
{

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			BlurImageX.at<uchar>(i, j) = (int)Gx(i, j);
			BlurImageY.at<uchar>(i, j) = (int)Gy(i, j);
		}
	}
}


int main()
{
	BlurBulk();
	imshow("Image", Image);
	imshow("BlurX", BlurImageX);
	imshow("BlurY", BlurImageY);
	Gxy();
//	Gtheta();
	waitKey(0);
	return 0;
}
*/