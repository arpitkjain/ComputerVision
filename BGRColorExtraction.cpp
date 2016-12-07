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

Mat Image = imread("C:\\Users\\Arpit Jain\\Pictures\\Camera Roll\\WIN_20161206_17_27_02_Pro.jpg", CV_LOAD_IMAGE_COLOR);
Mat DetectedImage(Image.rows, Image.cols, CV_8UC3, Scalar(0));

int color[3] = { 180, 180, 180 };
int T = 30;

void BinaryImage(int dummy2, void* dummy)
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
			if (condition==1)
			for (int k = 0; k<3; k++)
			{
				DetectedImage.at<Vec3b>(i, j)[k] = Image.at<Vec3b>(i, j)[k];
			}
			else
			for (int k = 0; k<3; k++)
			{
				DetectedImage.at<Vec3b>(i, j)[k] = 0;
			}
		}
	}
	
	//Canny(DetectedImage, DetectedImage, 10, 30);
	imshow("Color", DetectedImage);


}


int main()
{
	BinaryImage(10, 0);
	namedWindow("Color", CV_WINDOW_AUTOSIZE);
	createTrackbar("T", "Color", &T, 100, BinaryImage, 0);
	createTrackbar("R", "Color", &color[2], 255, BinaryImage);
	createTrackbar("G", "Color", &color[1], 255, BinaryImage);
	createTrackbar("B", "Color", &color[0], 255, BinaryImage);
	waitKey(0);
	return 0;

}
*/