


/*



int isvalid(int x, int y)
	{
		if ((x < Image.rows) && (x >= 0) && (y < Image.cols) && (y >= 0))
		return 1;
		else
		return 0;
	}







void BinaryImage(int T, void* dummy)
	{
		for (int i = 0; i < Image.rows; i++)
		{
			for (int j = 0; j < Image.cols; j++)
			{
				Image2.at<uchar>(i, j) = Image.at<uchar>(i, j)>T ? 255 : 0;
			}
		}

		imshow("Binary", Image2);

	}





	
void ImageUpdate(int var, void* userdataPointer)
	{
		//Make sure you typecast userdataPointer properly
		// Mat* img = (Mat*)userdataPointer;
	
		imshow("WindowName", Image2);
	}


createTrackbar("TrackerName", "WindowName", &Var, MAX_VALUE, ImageUpdate, &userdata); 


float Convolution(int k, int m, Mat KernelMatrix )
{
	float sumx = 0;
	float counter=0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (isvalid(k + i, m + j))
			{
				sumx += KernelMatrix[i][j] * (float)Image.at<uchar>(k + i, m + j);
				counter+= KernelMatrix[i][j];
			}

		}
	}
	return (sumx/counter);
}

struct GVal
{
	float x;
	float y;
	float mag = hypot(x, y);
};

*/

