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

int x = Image.rows * 2, y = Image.cols*2;
Mat ResImage(x, y, CV_8UC1);

int main()
{
	for (int i = 0; i < ResImage.rows; i++)
	{
		for (int j = 0; j < ResImage.cols; j++)
		{
			x = i / 2; y = j / 2;
			ResImage.at<uchar>(i, j) = Image.at<uchar>(x, y);
		}
	}
	namedWindow("Resized", CV_WINDOW_KEEPRATIO);
	imshow("Original", Image);
	imshow("Resized", ResImage);
	waitKey(0);
	return 0;


}
*/