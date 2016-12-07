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
#include <queue>

using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Color.png", CV_LOAD_IMAGE_COLOR);
Mat NewImage(Image.rows, Image.cols, CV_8UC3);

int T = 0;

void WrappingFunction(int dummy, void*dummy2)
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			int ji = ((j - T + Image.cols*2) % Image.cols);
			for (int k = 0; k < 3; k++)
			{
				NewImage.at<Vec3b>(i, j)[k] = Image.at<Vec3b>(i, ji)[k];
			}
		}
	}
	imshow("Original", Image);
	imshow("Wrapped", NewImage);
}


int main()
{
	namedWindow("Wrapped", CV_WINDOW_AUTOSIZE);
	createTrackbar("Wrap", "Wrapped", &T, 600, WrappingFunction, 0);
	WrappingFunction(0, 0);
	waitKey(0);
	return 0;
}
*/