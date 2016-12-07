/*
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <algorithm>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

Mat Image = imread("C:\\Users\\Arpit Jain\\Desktop\\IP Workshop Notes\\Lenna.png", CV_LOAD_IMAGE_GRAYSCALE);

int Frequencies[26];
int FancyFreq[256];
int MaxH=0;


void AnalyzeData(void)
{
	int x;

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			x = Image.at<uchar>(i, j) / 10;
			Frequencies[x]++;
		}								//Frequncies created
	}
}



void DisplayData(void)
{
	
	cout << endl << "\t\t\t\t" << "HISTOGRAM" << endl;
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << ((i) * 10) << "-" << ((i + 1) * 10) << "\t";
		for (int j = 0; j < Frequencies[i] / 120; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}


void AnalyzeFancyData(void)
{
	int x;

	for (int i = 0; i < Image.rows; i++)
	{
		for (int j = 0; j < Image.cols; j++)
		{
			x = Image.at<uchar>(i, j);
			FancyFreq[x]++;
		}								//Frequncies created
	}
}

void MaximumH(void)
{
	for(int i = 0; i < 256; i++)
	{
		if (FancyFreq[i]>MaxH)
			MaxH = FancyFreq[i];
	}
}


void DisplayFancyData()
{
	Mat HistImg(640, 640, CV_8UC1);

	int ColWidth = 640 / 256;

	int i,x = 0;
	for ( i = 0; i < HistImg.rows; i++)
	
	{
		for (int j = 0; j < (HistImg.cols - (FancyFreq[x] * 640 )/ MaxH); j++)
		{
			HistImg.at<uchar>(i, j) = 255;
		}								
		
		if ((i+1)%ColWidth == 0)
		{
			x++;
		}
		
	}
	
	imshow("Histogram", HistImg);
	waitKey(0);

}

int main()
{
	
	AnalyzeFancyData();
	
	MaximumH();
	
	DisplayFancyData();
	//cout << "sg";
	cin >> MaxH; 

	return 0;

}
*/