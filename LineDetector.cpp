
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

int color[3] = { 236 * 180 / 240, 189 * 255 / 240, 128 * 255 / 240 };
int T[3] = { 10, 15, 200 };

int starter = 0;

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

int xi = 150, xf = 150, yi = 150, yf = 150;


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
	int counter = 0;
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			if (DetectedImage->at<uchar>(i, j) == 255)
			{
				x += i;
				y += j;
				counter++;
			}
		}
	}
	if (counter != 0)
	{
		x = x / counter;
		y = y / counter;
	}

	Coord temp(x, y);
	return temp;
}

void MakeLine(Coord Position, Mat* Drawing, int Rows, int Cols)
{
	if (starter == 0)
	{
		xi = xf = Position.x; yi = yf = Position.y;
		starter++;
	}
	
	if (Position.x != 0 || Position.y != 0)
	{
		xf = Position.x; yf = Position.y;
	}

	line(*Drawing, Point2i(Cols - yi - 1, xi), Point2i(Cols - yf - 1, xf), CV_RGB(237, 28, 36), 4);

	xi = xf; yi = yf;

}


int main()
{
	
	
	vc >> Image;
	Mat Drawing(Image.rows, Image.cols, CV_8UC3, Scalar(255, 255, 255));
	

	while (1)
	{

		vc >> Image;
		Mat DetectedImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));


		cvtColor(Image, Image, CV_BGR2HSV);
		//
		//BinaryImage(&DetectedImage);
		inRange(Image, Scalar(((color[0] - T[0])<0 ? (0) : (color[0] - T[0])), ((color[1] - T[1])<0 ? (0) : (color[1] - T[1])), ((color[2] - T[2])<0 ? (0) : (color[2] - T[2]))), Scalar(((color[0] + T[0])>179 ? (179) : (color[0] + T[0])), ((color[1] + T[1])>255 ? (255) : (color[1] + T[1])), ((color[2] + T[2])>255 ? (255) : (color[2] + T[2]))), DetectedImage);

		
		//
		Coord Position = FindPosition(&DetectedImage);

		
		MakeLine(Position, &Drawing, Image.rows, Image.cols);
		

		namedWindow("Drawing", CV_WINDOW_KEEPRATIO);
		imshow("Drawing", Drawing);
		//imshow("Binary Image", DetectedImage);
		
		char ch = waitKey(1);
		if (ch == ' ')
			break;
	}

	return 0;
}
