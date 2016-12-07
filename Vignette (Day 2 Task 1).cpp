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

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_COLOR);

float intense = 1 ;
float dist;

int main()
{
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				dist = (hypot((float)(i - Image.cols / 2), (float)(j - Image.rows / 2)));
				Image.at<Vec3b>(i, j)[k] /= 1 +  dist/ intense;
			}
		}
	}
	imshow("Vignette", Image);
	waitKey(0);
	return 0;
}
*/