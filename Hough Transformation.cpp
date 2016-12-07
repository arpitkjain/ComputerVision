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
Mat ModifiedImage(Image.rows, Image.cols, CV_8UC1, Scalar(255));

float theta= 3.14/4.0;
int r= 120;
Point2i borderpoints[2];

// theta from 
int c = 0;

int Condition(int a, int b)
{	
	float x = a, y = b;
	if (((int)(x*cos(theta) + y*cos(theta))) == r)
		return 1;
	else
		return 0;
}


void CallLine(int dummy, void* dummy2)
{
	for (int i = 0; i < Image.rows; i = i + Image.rows - 1)
	{					//Horizontal borders
		for (int j = 0; j < Image.cols; j++)
		{
			if (Condition(i, j) == 1)
			{
				borderpoints[c++] = Point2i(i, j);
				break;
			}
		}
	}
	if (c<2)
	for (int j = 0; j < Image.cols; j = j + Image.cols - 1)
	{
		for (int i = 1; i < Image.rows - 1; i++)
		{
			if (Condition(i, j) == 1)
			{
				borderpoints[c++] = Point2i(i, j);
				break;
			}
		}

	}
	cout << borderpoints[0].x << " " << borderpoints[0].y << endl;
	cout << borderpoints[1].x << " " << borderpoints[1].y;

	line(ModifiedImage, borderpoints[0], borderpoints[1], (0, 0, 0), 4);
	imshow("Line", ModifiedImage);
	waitKey(0);
}


int main()
{
	namedWindow("Line", CV_WINDOW_AUTOSIZE);
	createTrackbar("R", )
	return 0;
}
*/