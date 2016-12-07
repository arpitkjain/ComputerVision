/*
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat Image2(Image.rows, Image.cols, CV_8UC1);
	namedWindow("LennaBinary", WINDOW_AUTOSIZE);
	int T;
	createTrackbar("T", "LennaBinary", &T, 255); 

	//imshow("LennaBinary", Image);

	while (1)
	{

		for (int i = 0; i < Image.rows; i++)
		{
			for (int j = 0; j < Image.cols; j++)
			{
				Image2.at<uchar>(i, j) = Image.at<uchar>(i, j)>T ? 255 : 0;
			}
		}

		imshow("LennaBinary", Image2);
		
		char ch = waitKey(5);
		if (ch == ' ')
			break;
	}


	waitKey(0);
	return 0;
}
*/