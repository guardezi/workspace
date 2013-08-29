
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define NOI 20 //noi = number of images


/*================================================================================
 MAIN
 ==================================================================================*/
int main()
{
	int i, j, p;
	int k = 3; // k nearest
	double soma = 0; //somatório da distancia
	double distancia;
	int correct; // resultados corretos
	int erros; // resultados incorretos
	int cls1 = 0, cls2 = 0, cls3 = 0, cls4 = 0, cls; // classes

typedef struct
{
	double data;
	int class;
}matrix;

matrix **trainingVectors = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	trainingVectors[i] = (matrix*) malloc(NOI*sizeof(matrix));
}
matrix **testVectors = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	testVectors[i] = (matrix*) malloc(NOI*sizeof(matrix));
}
matrix **DistanceVectors = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	DistanceVectors[i] = (matrix*) malloc(NOI*sizeof(matrix));

}
matrix **trainingClasses = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	trainingClasses[i] = (matrix*) malloc(NOI*sizeof(matrix));

}
matrix **testClasses = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	testClasses[i] = (matrix*) malloc(NOI*sizeof(matrix));

}
matrix **ResultVector = (matrix**) malloc (NOI* sizeof(matrix*));
for (i=0; i<NOI; i++)
{
	ResultVector[i] = (matrix*) malloc(NOI*sizeof(matrix));

}



//==================================MOMENTOS DE HU====================================
//momentos
CvMoments Moments;
CvHuMoments HuMoments;

IplImage* images;
	p = 0;
	//treinamento
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 6; j++)
		{
			//carrega imagens de treinamento
			char caminho[20];
			char a;
			a = i + 48;
			//printf("%c",a);
			strcpy(caminho, "Treino/");
			caminho[7] = a;
			caminho[8] = '/';
			a = j + 48;

			caminho[9] = a;
			caminho[10] = '\0';
			strcat(caminho, ".png");
			printf("%s", caminho);
			images = cvLoadImage(caminho, 0); //img_file[i], 1
			cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
			cvShowImage("Example1", images);
			//cvWaitKey(0);

			//calcula momentos/huMoments
			cvMoments(images, &Moments, 0);
			cvGetHuMoments(&Moments, &HuMoments);

			//passa para a matriz de treinamento
			trainingVectors[p][0].data = HuMoments.hu1;
			trainingVectors[p][1].data = HuMoments.hu2;
			trainingVectors[p][2].data = HuMoments.hu3;
			trainingVectors[p][3].data = HuMoments.hu4;
			trainingVectors[p][4].data = HuMoments.hu5;
			trainingVectors[p][5].data = HuMoments.hu6;
			trainingVectors[p][6].data = HuMoments.hu7;

			//passa para a matriz de classes de  treinamento
			trainingVectors[p][0].class = i;


			//imprime momentos
			printf("Hu Moment hu1: %.12f\n", trainingVectors[p][0].data = HuMoments.hu1);
			printf("Hu Moment hu2: %.12f\n", trainingVectors[p][1].data = HuMoments.hu2);
			printf("Hu Moment hu3: %.12f\n", trainingVectors[p][2].data = HuMoments.hu3);
			printf("Hu Moment hu4: %.12f\n", trainingVectors[p][3].data = HuMoments.hu4);
			printf("Hu Moment hu5: %.12f\n", trainingVectors[p][4].data = HuMoments.hu5);
			printf("Hu Moment hu6: %.12f\n", trainingVectors[p][5].data = HuMoments.hu6);
			printf("Hu Moment hu7: %.12f\n", trainingVectors[p][6].data = HuMoments.hu7);
			p++;
		}
	}


	p = 0;
	//teste
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 6; j++)
		{
			//carrega imagens de teste
			char caminho[20];
			char a;
			a = i + 48;
			//printf("%c",a);
			strcpy(caminho, "Testeo/");
			caminho[7] = a;
			caminho[8] = '/';
			a = j + 48;

			caminho[9] = a;
			caminho[10] = '\0';
			strcat(caminho, ".png");
			printf("%s", caminho);
			images = cvLoadImage(caminho, 0); //img_file[i], 1
			cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
			cvShowImage("Example1", images);
			//cvWaitKey(0);

			//calcula momentos/huMoments
			cvMoments(images, &Moments, 0);
			cvGetHuMoments(&Moments, &HuMoments);

			//passa para a matriz de teste
			testVectors[p][0].data = HuMoments.hu1;
			testVectors[p][1].data = HuMoments.hu2;
			testVectors[p][2].data = HuMoments.hu3;
			testVectors[p][3].data = HuMoments.hu4;
			testVectors[p][4].data = HuMoments.hu5;
			testVectors[p][5].data = HuMoments.hu6;
			testVectors[p][6].data = HuMoments.hu7;

			//matriz de classes
			testClasses[0][p].class = i;


			//imprime momentos
			printf("Hu Moment hu1: %.12f\n", testVectors[p][0].data = HuMoments.hu1);
			printf("Hu Moment hu2: %.12f\n", testVectors[p][1].data= HuMoments.hu2);
			printf("Hu Moment hu3: %.12f\n", testVectors[p][2].data = HuMoments.hu3);
			printf("Hu Moment hu4: %.12f\n", testVectors[p][3].data = HuMoments.hu4);
			printf("Hu Moment hu5: %.12f\n", testVectors[p][4].data = HuMoments.hu5);
			printf("Hu Moment hu6: %.12f\n", testVectors[p][5].data = HuMoments.hu6);
			printf("Hu Moment hu7: %.12f\n", testVectors[p][6].data = HuMoments.hu7);
			p++;
		}
	}


	// ======================================KNN===========================================

	//Distancia euclidiana
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			for (p = 0; p < 7; p++)
			{
				soma += pow(testVectors[i][p].data - trainingVectors[j][p].data, 2);
			}
			distancia = sqrtf(soma);
			DistanceVectors[i][j].data =distancia;
			soma = 0;
		}
		//ordena vetor de distancias[q] e o trainingClasses[q]
		//selection(DistanceVectors,trainingClasses,0, 6, q);
	}


	//encontramos a classe pelos k primeiros
	for (i = 0; i < NOI; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (trainingClasses[i][j].data == 1)
				cls1 += 1;
			if (trainingClasses[i][j].data == 2)
				cls2 += 1;
			if (trainingClasses[i][j].data == 3)
				cls3 += 1;
			if (trainingClasses[i][j].data == 4)
				cls4 += 1;
		}
		if ((cls1 > cls2) && (cls1 > cls3) && (cls1 > cls4))
			cls = 1;
		if ((cls2 > cls1) && (cls2 > cls3) && (cls2 > cls4))
			cls = 2;
		if ((cls3 > cls2) && (cls3 > cls1) && (cls3 > cls4))
			cls = 3;
		if ((cls4 > cls1) && (cls4 > cls2) && (cls4 > cls3))
			cls = 4;
		if ((cls4 == cls1) && (cls4 == cls2) && (cls4 == cls3))
			cls = 1; //trainingVectors[j][0].class;
		cls1 = 0, cls2 = 0, cls3 = 0, cls4 = 0; // zera as classes
		ResultVector[0][j].class  = cls;
	}

	correct=0;
	 //compara resultados
	 for (i=0;i<NOI;i++)
	 {
	 if (ResultVector[0][j].class ==  testClasses[0][j].class )
	 correct += 1;
	 if (ResultVector[0][j].class !=  testClasses[0][j].class )
	 erros += 1;
	 }


	 //======================================================================================================================================================
	 printf("corretos: %d", correct);
	 //printf("Time: %d\nAccuracy: %d%\n\n", (int)time, (int)correct*100/(int)NOI);

	 //cvReleaseImage( &img_8uc1 );*/

	cvWaitKey(0);
	return 0;


}
