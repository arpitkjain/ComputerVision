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

VideoCapture vc(0);
Mat Image;// = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\ScreenGrab4.png", CV_LOAD_IMAGE_COLOR);


int color[3] = { 90, 90, 90 };
int T = 30;
char ch;

Mat BinaryImage(Mat DetectedImage, void* dummy)
{
	for (int i = 0; i < Image.rows; i++)
	
	{
		for (int j = 0; j < Image.cols; j++)
		{
			int condition = 1;
			for (int k = 0; k<3; k++)
			{
				if (!((Image.at<Vec3b>(i, j)[k] <= ((color[k] + T)>255 ? (255) : (color[k] + T))) && (Image.at<Vec3b>(i, j)[k] >= ((color[k] - T)<0 ? (0) : (color[k] - T)))))
				{
					condition = 0;
					break;
				}
			}
			if (condition == 1)
			{
				DetectedImage.at<uchar>(i, j) = 255;
			}
			else
				DetectedImage.at<uchar>(i, j) = 0;
		}
	}

	//Canny(DetectedImage, DetectedImage, 10, 30);
	// imshow("Color", DetectedImage);
	return DetectedImage;

}


int main()
{
	
	while (1)
	{

		vc >> Image;
		Mat src(Image.rows, Image.cols, CV_8UC1, Scalar(0));

		//if (frame != NULL)

		BinaryImage(src, 0);



		if (Image.data)
		{
			imshow("WinName", src);
			ch = waitKey(1);
		}
		if (ch == ' ')
			break;
	}
	
	return 0;

}
*/