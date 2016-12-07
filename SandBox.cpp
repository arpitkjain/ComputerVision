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

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\RoboSoccer.mp4", CV_LOAD_IMAGE_GRAYSCALE);

int xi, xf, yi, yf;

void F(int event, int x, int y, int flags, void* dummy)
{
	xf = x; yf = y;

	


	imshow("Drawing", Image);
}


int main()
{
	namedWindow("Drawing", CV_WINDOW_AUTOSIZE);
	setMouseCallback("Drawing", F, 0);
	waitKey(0);
	return 0;

}
*/