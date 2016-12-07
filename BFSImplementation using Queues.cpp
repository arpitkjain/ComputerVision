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
#include <queue>

using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Color.png", CV_LOAD_IMAGE_GRAYSCALE);
Mat NewImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));

int counter = 0;

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

queue<Coord> MainStack;


int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}


int FurtherBranches(int k, int m)
{
	int flagBranch = 0;
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
				flagBranch = 1;
			}
		}
	}
	return flagBranch;
}


int main()
{
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
					Coord Dummy = MainStack.front();
					MainStack.pop();                                          // IMPORTANT
					int flagBranch = FurtherBranches(Dummy.x, Dummy.y);
					
				}
				if (MainStack.empty() != 0)
					cout << "Empty" << endl;
			}

		}
	}

	imshow("Detected", NewImage);
	waitKey(0);
	return 0;
}
*/
