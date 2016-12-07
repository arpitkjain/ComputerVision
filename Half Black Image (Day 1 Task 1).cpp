/*

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\Arpit\\Transfer\\Images\\NYC.jpg",CV_LOAD_IMAGE_COLOR);
 
int main()
{
	for (int i = Image.rows/2; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				Image.at<Vec3b>(i, j)[k] = 0;
			}
		}
	}
	namedWindow("Ta-Da", CV_WINDOW_NORMAL);
	imshow("Ta-Da", Image);
	waitKey(0);
	return 0;
}

*/