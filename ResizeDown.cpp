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

int x = Image.rows / 2, y = Image.cols / 2;
Mat ResImage(x, y, CV_8UC1);
int sumpix;

int main()
{
	for (int i = 0; i < Image.rows; i=i+2)
	{
		for (int j = 0; j < Image.cols; j=j+2)
		{
			sumpix = 0;
			for (int k = i; k < i + 2; k++)
			{
				for (int m = j; m < j + 2; m++)
				{
					sumpix += Image.at<uchar>(k, m);
				}
			}
			ResImage.at<uchar>(i/2, j/2) = sumpix / 4;
		}
	}
	//namedWindow("Resized", CV_WINDOW_KEEPRATIO);
	imshow("Original", Image);
	imshow("Resized", ResImage);
	waitKey(0);
	return 0;


}
*/