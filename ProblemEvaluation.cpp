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

Mat Image(400, 400, CV_8UC1, Scalar(255));


int isValid(int x, int y)
{
	if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
	else
		return 0;
}

int xi, xf, yi, yf;

void F(int event, int x, int y, int flags, void* dummy)
{
	xf = x; yf = y;



	line(Image,Point2i (xi, yi), Point2i (xf, yf), (0, 0, 0), 4);

	xi = xf; yi = yf;
	
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