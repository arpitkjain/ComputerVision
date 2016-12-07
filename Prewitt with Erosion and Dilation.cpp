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

Mat Modified(Image.rows, Image.cols, CV_8UC1);
Mat Modified2(Image.rows, Image.cols, CV_8UC1);

float GaussMat[3][3] = { { -1, 0, 1 }, { -1, 0, 1 }, { -1, 0, 1 } };

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
			Diagonal.at<uchar>(i, j) = Diagonal.at<uchar>(i, j)>25 ? 255 : 0;
		}
	}
	imshow("Diagonal", Diagonal);
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

void Erosion()
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			int flag = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int m = 0; m < 3; m++)
				{
					if (isvalid(k - 1 + i, m - 1 + j))
					{
						if (Diagonal.at<uchar>(i, j)>Diagonal.at<uchar>(i + k - 1, j + m - 1))
						{
							Modified.at<uchar>(i, j) = 0;
							flag = 1;
							break;
						}
					}
				}
			}
			if (!flag)
				Modified.at<uchar>(i, j) = Diagonal.at<uchar>(i, j);
		}
	}
}

void Dilation()
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			int flag = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int m = 0; m < 3; m++)
				{
					if (isvalid(k - 1 + i, m - 1 + j))
					{
						if (Modified.at<uchar>(i, j)<Modified.at<uchar>(i + k - 1, j + m - 1))
						{
							Modified2.at<uchar>(i, j) = 255;
							flag = 1;
							break;
						}
					}

				}
			}
			if (!flag)
				Modified2.at<uchar>(i, j) = Modified.at<uchar>(i, j);
		}
	}
}
int main()
{
	BlurBulk();
	imshow("Image", Image);
	//imshow("BlurX", BlurImageX);
	//imshow("BlurY", BlurImageY);
	Gxy();
	Erosion();
	Dilation();
	imshow("Erroded Only", Modified);
	imshow("Final", Modified2);
	//Gtheta();
	waitKey(0);
	return 0;
}
*/