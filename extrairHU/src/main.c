#ifdef _CH_
#pragma package <opencv>
#endif

#include <cv.h>
#include <highgui.h>
#include <cvaux.h>
#include <stdio.h>
#include <time.h>

const char *VENTANA="Blob detection";

IplImage* imagen;
IplImage* roi;
IplImage* smooth;
IplImage* threshold;
IplImage* open_morf;
IplImage* blobResult;
IplImage* img_contornos;
CvMoments moments;
CvHuMoments humoments;
CvSeq* contour;
CvSeq* contourLow;

int main( int argc, char** argv )
{
	srand ( time(NULL) );
	if(argc >= 2 )
	{
		char* filename= argv[1];
		//load image  in gray level
		imagen=cvLoadImage(filename,0);
		//load image in RGB
//		imagen_color=cvLoadImage(filename,1);
	}else{
		printf("Use:\n\t%s image\n",argv[0]);
		return 0;
	}

	//Create needed images
	smooth= cvCreateImage(cvSize(imagen->width, imagen->height), IPL_DEPTH_8U, 1);
	threshold= cvCreateImage(cvSize(imagen->width, imagen->height), IPL_DEPTH_8U, 1);
	open_morf= cvCreateImage(cvSize(imagen->width, imagen->height), IPL_DEPTH_8U, 1);

	//Init variables for countours
	contour = 0;
	contourLow = 0;
	//Create storage needed for contour detection
	CvMemStorage* storage = cvCreateMemStorage(0);
	cvCopyImage(imagen,threshold);

	//Smooth image
	cvSmooth(threshold, threshold, CV_GAUSSIAN, 3, 0, 0, 0);


//	threshold image
	cvThreshold(threshold, threshold, 0, 255, CV_THRESH_BINARY_INV);

	//Morfologic filters

	cvDilate(threshold, threshold, NULL,5);
	cvErode(threshold, threshold, NULL,5);

	cvSetImageROI(threshold, cvRect(10, 15, 150, 250));

	/* create destination image
	   Note that cvGetSize will return the width and the height of ROI */
	IplImage *img2 = cvCreateImage(cvGetSize(threshold),
			threshold->depth,
			threshold->nChannels);

	/* copy subimage */
	cvCopy(threshold, img2, NULL);

	/* always reset the Region of Interest */
	cvResetImageROI(threshold);
	cvNamedWindow("res", 1);
	cvShowImage("res",img2);
	cvWaitKey(1000);


	cvMoments(threshold, &moments,1);
	//	Now calculate hu moments
	cvGetHuMoments(&moments, &humoments);

	//Show result.
	printf("%f %f %f %f %f %f %f ", humoments.hu1, humoments.hu2, humoments.hu3, humoments.hu4, humoments.hu5, humoments.hu6, humoments.hu7);

	return 0;
}
