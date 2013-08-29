#ifdef _CH_
#pragma package <opencv>
#endif

#ifndef _EiC
#include "cv.h"
#include "highgui.h"
#include "opencv2/imgproc/imgproc_c.h"
#include <stdio.h>
#endif

#define ARRAY  1

IplImage* imagen;
IplImage* roi;
IplImage* threshold;
CvMoments moments;
CvHuMoments humoments;

int main(int argc, char** argv) {
	if (argc >= 2) {
		char* filename = argv[1];
		imagen = cvLoadImage(filename, 0);
	}
	threshold = cvCreateImage(cvSize(imagen->width, imagen->height),IPL_DEPTH_8U, 1);
	cvThreshold(imagen, threshold, 0, 255, 1);
	cvErode(threshold, threshold, NULL, 5);
	cvDilate(threshold, threshold, NULL, 5);
//	calcular os momentos de hu para cada parte da imagem
	cvMoments(threshold, &moments, 1);
	cvGetHuMoments(&moments, &humoments);
	printf("%f %f %f %f %f %f %f ", humoments.hu1, humoments.hu2, humoments.hu3,humoments.hu4, humoments.hu5, humoments.hu6, humoments.hu7);

	return 0;
}
