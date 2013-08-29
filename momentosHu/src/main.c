#ifdef _CH_
#pragma package <opencv>
#endif

#ifndef _EiC
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#endif

int main(int argc, char** argv) {
	IplImage *imagen,*imagen2;
	int i, j,maior;
	float maior2;

//	guarda o valor do pixel da imagem
	CvScalar elemento;

//	ler imagen passada por parametro
	if (argc >= 2) {
		char* filename = argv[1];
		imagen = cvLoadImage(filename, 0);
	}
//	Limearizando a imagen
	float soma[imagen->height];
	cvThreshold(imagen, imagen, 127, 255, CV_THRESH_BINARY);
	cvErode(imagen, imagen, NULL, 1);
	cvDilate(imagen, imagen, NULL, 1);
	cvThreshold(imagen, imagen, 127, 255, CV_THRESH_BINARY_INV);
	imagen2=imagen;

	imagen=cvCreateImage(cvSize(100,100),imagen->depth,imagen->alphaChannel);
	cvResize(imagen2,imagen,1);
	//printf("\n");

	maior=0;
	for (i = 0; i < 100; i++) {
		soma[i] = 0;
		for (j = 0; j < 100; j++) {
			elemento = cvGet2D(imagen, i, j);
			if (elemento.val[0] == 0) {
				soma[i]++;
			}
		}
		if(soma[i]>soma[maior])
						maior=i;
	}

//	printf("\n");
	maior2=soma[maior];
	//printf("maior: %f\n",maior2);
	for (i = 0; i < imagen->height; i++) {
		//soma[i]=soma[i]/maior;
		printf("%.1f ",soma[i]/maior2);
	}




//	cvNamedWindow("Threshold", 1);
//	cvShowImage("Threshold", imagen);
//	cvWaitKey(50000);
//	i = cvCountNonZero(imagen);
//	printf("%i\n", i);

	return 1;
}
