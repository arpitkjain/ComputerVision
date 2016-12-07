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

int color[3] = { 51 * 180 / 240, 180 * 255 / 240, 143 * 255 / 240 };
int T[3] = { 100, 10, 15 };


struct Coord
{
	int x;
	int y;
	Coord(int p, int q)
	{
		x = p;
		y = q;
	}
};




VideoCapture vc(0);
Mat Image;


void BinaryImage(Mat* DetectedImage)
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
			{
				DetectedImage->at<uchar>(i, j) = 255;
			}
		}
	}

}


Coord FindPosition(Mat* DetectedImage)
{
	long int x = 0, y = 0;
	int counter = 1;
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			if (DetectedImage->at<uchar>(i, j) == 255)
			{
				//x += i;
				y += j;
				counter++;
			}
		}
	}
	//x = x / counter;
	y = y / counter;

	Coord temp(x, y);
	return temp;
}

void LeftOrRight(Coord Position)
{
	if (Position.y < Image.cols / 3)
		cout << "Right" << endl;
	else if (Position.y>2 * Image.cols / 3)
		cout << "Left" << endl;
	else
		cout << "Center" << endl;
}


void MakeMarkers(Mat* DetectedImage)
{
	for (int j = DetectedImage->cols / 3; j < DetectedImage->cols; j = j + DetectedImage->cols / 3)
	{
		for (int i = 0; i < DetectedImage->rows; i++)
		{
			DetectedImage->at<uchar>(i, j) = 255;
		}
	}
}

int main()
{
	
	while (1)
	{

		vc >> Image;
		Mat DetectedImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));

		//
		//BinaryImage(&DetectedImage);
		inRange(Image, Scalar(((color[0] - T[0])<0 ? (0) : (color[0] - T[0])), ((color[1] - T[1])<0 ? (0) : (color[1] - T[1])), ((color[2] - T[2])<0 ? (0) : (color[2] - T[2]))), Scalar(((color[0] + T[0])>179 ? (179) : (color[0] + T[0])), ((color[1] + T[1])>255 ? (255) : (color[1] + T[1])), ((color[2] + T[2])>255 ? (255) : (color[2] + T[2]))), DetectedImage);

		
		//
		Coord Position = FindPosition(&DetectedImage);

		
		//
		LeftOrRight(Position);


		MakeMarkers(&DetectedImage);

		imshow("Binary Image", DetectedImage);
		
		char ch = waitKey(1);
		if (ch == ' ')
			break;
	}

	return 0;
}

*/