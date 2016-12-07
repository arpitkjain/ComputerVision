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

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
Mat ModifiedImage(Image.rows, Image.cols, CV_8UC1);

void CED(int T, void* dummy)
{
	Canny(Image, ModifiedImage, (double)T, (double)(T * 3));
	imshow("Canny", ModifiedImage);
}

int main()
{
	int x = 50;
	namedWindow("Canny", CV_WINDOW_AUTOSIZE);
	createTrackbar("LTh", "Canny", &x, 120, CED, 0);
	CED(50, 0);
	
	waitKey(0);
	return 0;
}
*/