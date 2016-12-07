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
#include <opencv2\video\background_segm.hpp>

using namespace cv;
using namespace std;


int main() {

	//BackgroundSubtractorMOG bgs; 
	double largest_area = 0; int largest_contour_index = 0; Rect bounding_rect;
	Mat frame; Mat back; Mat fore, src_gray, threshold_output;
	VideoCapture cap(0);

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

	namedWindow("MyVideoa", CV_WINDOW_AUTOSIZE);


	while (1)
	{
		cap >> frame;

		cvtColor(frame, src_gray, CV_BGR2GRAY);

		//bgs.operator()(src_gray, src_gray);


		imshow("MyVideoa", src_gray);
		vector<vector<Point>> contours; // Vector for storing contour
		vector<Vec4i> hierarchy;

		findContours(src_gray, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); // Find the contours in the image

		for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
		{

			double a = contourArea(contours[i], false);  //  Find the area of contour
			if (a>largest_area){
				largest_area = a;
				largest_contour_index = i;                //Store the index of largest contour
				drawContours(frame, contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point()); // Find the bounding rectangle for biggest contour
			}




		}

		// read a new frame from video



		imshow("MyVideo", frame); //show the frame in "MyVideo" window


		if (waitKey(1) == ' ') //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}
*/