/*
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat Image(640, 640, CV_8UC1);
	int count1 = 0, count2 = 0;
	int color = 1;

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			
			Image.at<uchar>(i, j) = (255 + color) % 256;

			count1++;
			if (count1 == 80)
			{
				count1 = 0;
				color = (color + 1) % 2;   // or you can negate color !color
			}


		}
		count2++;
		if (count2 == 80)
		{
			count2 = 0;
			color = (color + 1) % 2; 
		}
		
	}
	imshow("Checkerboard", Image);
	waitKey(0);
	return 0;
}
*/