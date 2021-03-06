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

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\ColorLess.png", CV_LOAD_IMAGE_GRAYSCALE);
Mat NewImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));

int counter = 0;

struct Coord
{
	int x;
	int y;
};

int isvalid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}


void DFS(int k, int m)
{
	NewImage.at<uchar>(k, m) = 255 / counter;
	
	for (int i = -1; i <=1; i++)
	{
		for (int j = -1; j <=1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (isvalid(k + i, m + j))
			if ((Image.at<uchar>(k + i, m + j) != 255) && (NewImage.at<uchar>(k + i, m + j))==0)
			{
				DFS(k + i, m + j);
			}
		}
	}
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
				DFS(i, j);
				
			}
		}
	}
	

	imshow("Orginal", Image);
	imshow("Blobs", NewImage);
	waitKey(0);
	return 0;

}
*/