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
	Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_COLOR);
	Mat ImageGray(Image.rows, Image.cols, CV_8UC1);
	int sum;

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			sum = 0;
			
			for (int k = 0; k < 3; k++)
			{
				sum += Image.at<Vec3b>(i, j)[k];		// B:0.11 G:0.59 R: 0.30
			}
			
			int imin, imax;
			imin = min({Image.at<Vec3b>(i, j)[0], Image.at<Vec3b>(i, j)[1], Image.at<Vec3b>(i, j)[2]});
			imax = max({ Image.at<Vec3b>(i, j)[0], Image.at<Vec3b>(i, j)[1], Image.at<Vec3b>(i, j)[2] });
				
			
			ImageGray.at<uchar>(i, j) = (imin+imax) / 2;
			
			
				for (int n = 0; n< 3; n++)
			{
					Image.at<Vec3b>(i, j)[n] = sum/3;
			}
		}
	}
	imshow("Image", Image);
	imshow("Grayscaled Image", ImageGray);
	waitKey(0);
	return 0;
}
*/