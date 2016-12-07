// ComputerVision2.cpp : Defines the entry point for the console application.
//

/*#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/
/*
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}

void createimagesampe()
{
	Mat temp2(500, 500, CV_8UC3, 255);
	for (int i = 0; i < temp2.rows; i++)
	{
		for (int j = 0; j < temp2.cols; j++)
		{
			temp2.at<Vec3b>(i, j)[2] = 255-i/2;
			temp2.at<Vec3b>(i, j)[1] = j/2;
			temp2.at<Vec3b>(i, j)[0] = 0;
		}
	}
	displayimage(temp2, "random");
}

int main()
{
	createimagesampe();
	int iKey = waitKey(50);
	waitKey(0);  //Used as an alternative to getch()
	return 0;
}
*/