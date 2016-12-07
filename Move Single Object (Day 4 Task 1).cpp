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
#include <stack>


using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Color.png", CV_LOAD_IMAGE_GRAYSCALE);
Mat Image2 = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Color.png", CV_LOAD_IMAGE_COLOR);

Mat NewImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));
Mat WrapNewImage(Image.rows, Image.cols, CV_8UC3);

int T = 0;

int counter = 0;
int c = 3;

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

stack<Coord> MainStack;
stack<Coord> Moved;

int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}


void FurtherBranches(int k, int m)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (isvalid(k + i, m + j))
			if ((Image.at<uchar>(k + i, m + j) != 255) && (NewImage.at<uchar>(k + i, m + j)) == 0)
			{
				NewImage.at<uchar>(k + i, m + j) = 255 / counter;
				Coord Fast(k + i, m + j);
				MainStack.push(Fast);
			}
		}
	}
}


void WrappingFunction(int dummy, void*dummy2)
{
	for (int i = 0; i < Image2.rows; i++)
	{
		for (int j = 0; j < Image2.cols; j++)
		{
			if (NewImage.at<uchar>(i, j) == 255 / c)
			{
				Coord Identified(i, j);
				Moved.push(Identified);
				for (int k = 0; k < 3; k++)
				{
					WrapNewImage.at<Vec3b>(i, j)[k] = 255;
				}
			}
			else
			for (int k = 0; k < 3; k++)
			{
				WrapNewImage.at<Vec3b>(i, j)[k] = Image2.at<Vec3b>(i, j)[k];
			}
		}
	}
	
	while (Moved.empty() == 0)
	{
		Coord Printed = Moved.top();
		int i = Printed.x; int j = Printed.y;
		int ji = ((j + T + Image2.cols * 2) % Image2.cols);
		for (int k = 0; k < 3; k++)
		{
			WrapNewImage.at<Vec3b>(i, ji)[k] = Image2.at<Vec3b>(i, j)[k];
		}
		Moved.pop();
	}
	
	imshow("Wrapped", WrapNewImage);
}



int main()
{
	
	imshow("Original", Image2);
	waitKey(5);
	cout << "Enter the object number (from top) you want to move: ";
	cin >> c;
	if (!(c == 1 || c == 2 || c == 3))
	{
		cout << "\n Idiot!";
		return -1;
	}

	
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			if ((Image.at<uchar>(i, j) != 255) && (NewImage.at<uchar>(i, j)) == 0)
			{
				counter++;
				NewImage.at<uchar>(i, j) = 255 / counter;
				Coord Fast(i, j);
				MainStack.push(Fast);
				while (MainStack.empty() == 0)
				{
					Coord Dummy = MainStack.top();
					MainStack.pop();                                          // IMPORTANT
					FurtherBranches(Dummy.x, Dummy.y);

				}
			}

		}
	}
	
	namedWindow("Wrapped", CV_WINDOW_AUTOSIZE);
	createTrackbar("Wrap", "Wrapped", &T, 600, WrappingFunction, 0);
	WrappingFunction(0, 0);


	//imshow("Detected", NewImage);
	waitKey(0);
	return 0;
}
*/

