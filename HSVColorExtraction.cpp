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

Mat Image = imread("C:\\Users\\Arpit Jain\\Pictures\\Camera Roll\\WIN_20161207_15_53_59_Pro.jpg", CV_LOAD_IMAGE_COLOR);
Mat DetectedImage(Image.rows, Image.cols, CV_8UC3, Scalar(0));

int color[3] = { 58 * 180 / 240, 28 * 255 / 240, 159 * 255 / 240 };
int T[3] = { 10, 10, 15 };

// 22, 208 255
// 69,69,69

void BinaryImage(int dummy2, void* dummy)
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			int condition = 1;
			
			if (!((Image.at<Vec3b>(i, j)[0] <= ((color[0] + T[0])>179 ? (179) : (color[0] + T[0]))) && (Image.at<Vec3b>(i, j)[0] >= ((color[0] - T[0])<0 ? (0) : (color[0] - T[0])))))
			{
				condition *= 0;
			}
			
			for (int k = 1; k<3; k++)
			{
				if (!((Image.at<Vec3b>(i, j)[k] <= ((color[k] + T[k])>255 ? (255) : (color[k] + T[k]))) && (Image.at<Vec3b>(i, j)[k] >= ((color[k] - T[k])<0 ? (0) : (color[k] - T[k])))))
				{
					condition *= 0;
					break;
				}
			}
			if (condition == 1)
			for (int k = 0; k<3; k++)
			{
				DetectedImage.at<Vec3b>(i, j)[k] = 255;
			}
		}
	}
	
	imshow("Color", DetectedImage);


}


int main()
{
	cvtColor(Image, Image, CV_BGR2HSV);
	BinaryImage(10, 0);
	namedWindow("Color", CV_WINDOW_AUTOSIZE);
	createTrackbar("T_S", "Color", &T[2], 150, BinaryImage, 0);
	createTrackbar("T_L", "Color", &T[1], 150, BinaryImage, 0);
	createTrackbar("T_H", "Color", &T[0], 150, BinaryImage, 0);
	createTrackbar("S", "Color", &color[2], 255, BinaryImage);
	createTrackbar("L", "Color", &color[1], 255, BinaryImage);
	createTrackbar("H", "Color", &color[0], 179, BinaryImage);
	waitKey(0);
	return 0;

}
*/