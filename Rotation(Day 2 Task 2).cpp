/*
#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<iostream>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_COLOR);

Mat RotImage(Image.cols, Image.rows, CV_8UC3);


int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}

void Rotate90()
{
	for (int i = 0; i < RotImage.rows; i++)
	{
		for (int j = 0; j < RotImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				RotImage.at<Vec3b>(i, j)[k] = Image.at<Vec3b>(j, i)[k];
			}
		}
	}
	imshow("Rotated 90 degrees", RotImage);
}

void Rotate270()
{
	for (int i = 0; i < RotImage.rows; i++)
	{
		for (int j = 0; j < RotImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				RotImage.at<Vec3b>(i, j)[k] = Image.at<Vec3b>(Image.rows - j - 1, Image.cols - i - 1)[k];
			}
		}
	}
	imshow("Rotated 270 degrees", RotImage);
}


int main()
{
	//Rotate90();
	//Rotate270();
	Rotate45();
	waitKey(0);
	return 0;
}
*/