/*
 * DisplayImage.cpp
 *
 *  Created on: 29/08/2013
 *      Author: guardezi
 */
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat image;
	image = imread(argv[1], 1);

	if (argc != 2 || !image.data) {
		cout << "No image data \n";
		return -1;
	}

	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);

	waitKey(0);

	return 0;
}

