/*
#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<iostream>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

Mat Image1 = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_COLOR);
Mat Image2 = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\RogueOne.jpg", CV_LOAD_IMAGE_COLOR);
Mat MorphImage(Image1.rows, Image2.cols, CV_8UC3);

float x=0.0;
int perc=0;
void Morphing(int,void*)
{
	x = ((float)perc) / 100;
	for (int i = 0; i < Image1.rows; i++)
	{
		for (int j = 0; j < Image1.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				MorphImage.at<Vec3b>(i, j)[k] = (x*((float)Image1.at<Vec3b>(i, j)[k]) + (1-x)*((float)Image2.at<Vec3b>(i, j)[k]));
			}
		}
	}
	imshow("Morphing", MorphImage);
}

int main()
{
	namedWindow("Morphing", CV_WINDOW_AUTOSIZE);
	createTrackbar("Morpher", "Morphing", &perc, 100, Morphing);
	Morphing(perc, 0);
	waitKey(0);
	return 0;
}
*/