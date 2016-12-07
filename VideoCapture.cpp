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
#include <stack>


using namespace cv;
using namespace std;


VideoCapture vc("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\RoboSoccer.mp4");
int ch;
float dist;
// for WebCam 0
Mat frame;
float intense = 100;
int main()
{
	while (1)
	{

		vc >> frame;
		//if (frame != NULL)
			
			Mat frame2(frame.rows, frame.cols, CV_8UC3);
			
			for (int i = 0; i < frame.rows; i++)
			{
				for (int j = 0; j < frame.cols; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						dist = (hypot((float)(i - frame.cols / 2), (float)(j - frame.rows / 2)));
						frame.at<Vec3b>(i, j)[k] /= 1 + dist / intense;
					}
				}
			}
			if (frame.data)
			{
				imshow("WinName", frame);
			 ch=waitKey(1); 
			}
			if (ch == ' ')
				break;
	}
	return 0;
}
*/