
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


int color[3] = { 22, 208, 255 };
int T[3] = { 69, 69, 69 };


struct Coord
{
	int x;
	int y;
	Coord(int p, int q)
	{
		x = p;
		y = q;
	}
};


VideoCapture vc("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\RoboSoccer.mp4");
Mat Image;

void BinaryImage(Mat* DetectedImage)
{
	for (int i = 0; i < Image.rows; i++)

	{
		for (int j = 0; j < Image.cols; j++)
		{
			int condition = 1;
			
			if (!((Image.at<Vec3b>(i, j)[0] <= ((color[0] + T[0])>179 ? (179) : (color[0] + T[0]))) && (Image.at<Vec3b>(i, j)[0] >= ((color[0] - T[0])<0 ? (0) : (color[0] - T[0])))))
			{
				condition *= 0;
			}
			
			for (int k = 1; k<3; k++)
			{
				if (!((Image.at<Vec3b>(i, j)[k] <= ((color[k] + T[k])>255 ? (255) : (color[k] + T[k]))) && (Image.at<Vec3b>(i, j)[k] >= ((color[k] - T[k])<0 ? (0) : (color[k] - T[k])))))
				{
					condition *= 0;
					break;
				}
			}
			if (condition == 1)
			{
				DetectedImage->at<uchar>(i, j) = 255;
			}
		}
	}

}


Coord FindPosition(Mat* DetectedImage)
{
	long int x = 0, y = 0;
	int counter = 0;
	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols * 3 / 4; j++)
		{
			if (DetectedImage->at<uchar>(i, j) == 255)
			{
				x += i;
				y += j;
				counter++;
			}
		}
	}
	x = x / counter;
	y = y / counter;

	Coord temp(x, y);
	return temp;
}

int LeftOrRightGoal(Coord Position)
{
	if ((Position.y < 63) && (Position.x<496) && (Position.x>229))
		return 1;
	else
		return 0;
}

int main()
{
	int GoalCounter = 0;
	int prevWhetherGoal = 0;
	int counterFrame = 0, prevcounterFrame = 0;
	while (1)
	{

		vc >> Image;
		counterFrame++;
		if (counterFrame%5==0)
		{
			Mat DetectedImage(Image.rows, Image.cols, CV_8UC1, Scalar(0));

			//
			//BinaryImage(&DetectedImage);

			inRange(Image, Scalar(((color[0] - T[0])<0 ? (0) : (color[0] - T[0])), ((color[1] - T[1])<0 ? (0) : (color[1] - T[1])), ((color[2] - T[2])<0 ? (0) : (color[2] - T[2]))), Scalar(((color[0] + T[0])>179 ? (179) : (color[0] + T[0])), ((color[1] + T[1])>255 ? (255) : (color[1] + T[1])), ((color[2] + T[2])>255 ? (255) : (color[2] + T[2]))), DetectedImage);

			//
			Coord Position = FindPosition(&DetectedImage);


			//
			int WhetherGoal = LeftOrRightGoal(Position);


			if (WhetherGoal == 1 && (counterFrame >= prevcounterFrame + 60))
			{
				GoalCounter++;
				prevcounterFrame = counterFrame;
				cout << "Goal! " << endl;
				cout << GoalCounter << " - 0" << endl;
				cout << "Timestamp: " << counterFrame * 37 / 558 << " seconds" << endl << endl;  //558frames 37s
			}
		}
			imshow("Image", Image);
		
			char ch = waitKey(1);
			if (ch == ' ')
				break;
	}


	return 0;
}
