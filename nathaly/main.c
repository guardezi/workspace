
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define NOI 20 //noi = number of images
/*
 * =============================SELECTION_SORT==============================
 */
//função que faz a troca de valores entre duas posições
void troca(CvMat *v, CvMat *h, long int a, long int b, long int row) {
	int aux, aux2;
	aux = ((long int*) (v->data.db + v->step * row))[a];
	aux2 = ((long int*) (h->data.db + h->step * row))[a];/*
	 ((long int*)(v->data.db + v->step*row))[a] = ((long int*)(v->data.db + v->step*row))[b];
	 ((long int*)(h->data.db + h->step*row))[a] = ((long int*)(h->data.db + h->step*row))[b];
	 ((long int*)(v->data.db + v->step*row))[b] = aux;
	 ((long int*)(h->data.db + h->step*row))[b] = aux2;*/
}

//Mínimo usado na função de seleção
int mininum(CvMat *v, long int a, long int b, long int row) {
	int i, m;
	i = a;
	m = a;
	while (i < b) {
		i++;
		if (((long int*) (v->data.db + v->step * row))[i] < ((long int*) (v->data.db + v->step * row))[m]) {
			m = i;
		}
	}
	return m;
}

int selection(CvMat *v, CvMat *h, long int a, long int b, long int row) {
	if (a >= b) {
		printf("\noi\n");
		return ((long int*) (v->data.db + v->step * row))[0];
		return ((long int*) (h->data.db + h->step * row))[0];
	}
	troca(v, h, a, mininum(v, a, b, row), row);
	//return selection(v,h, a+1, b,row);
}

//================================================================================

/*================================================================================
 MAIN
 ==================================================================================*/
int main() {

	/*
	 ==================================MOMENTOS DE HU====================================
	 */

	int i, t;
	int k = 3; // k nearest
	int q, p, r, l, j, f; // usado para for's no knn
	double soma = 0; //somatório da distancia
	double distancia;
	int correct; // resultados corretos
	int erros; // resultados incorretos
	double cls1 = 0, cls2 = 0, cls3 = 0, cls4 = 0, cls; // classes
	float maiorv, menorv;
	// momentos
	CvMoments Moments;
	CvHuMoments HuMoments;

	//cria matrizes
	CvMat *trainingVectors = cvCreateMat(NOI, 7, CV_32FC1);
	CvMat *testVectors = cvCreateMat(NOI, 7, CV_32FC1);
	//para o KNN
	CvMat *DistanceVectors = cvCreateMat(NOI, NOI, CV_32FC1);
	CvMat *trainingClasses = cvCreateMat(NOI, NOI, CV_32FC1);
	CvMat *testClasses = cvCreateMat(1, NOI, CV_32FC1);
	CvMat *ResultVector = cvCreateMat(1, NOI, CV_32FC1);

	IplImage* images;
	f = 0;
	//treinamento
	for (t = 1; t < 5; t++)
	{
		for (j = 1; j < 6; j++)
		{
			//carrega imagens de treinamento
			char caminho[20];
			char a;
			a = t + 48;
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
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[0] = HuMoments.hu1;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[1] = HuMoments.hu2;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[2] = HuMoments.hu3;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[3] = HuMoments.hu4;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[4] = HuMoments.hu5;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[5] = HuMoments.hu6;
			((double*) (trainingVectors->data.db + trainingVectors->step * f))[6] = HuMoments.hu7;

			//imprime momentos
			printf("Hu Moment hu1: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[0]);
			printf("Hu Moment hu2: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[1]);
			printf("Hu Moment hu3: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[2]);
			printf("Hu Moment hu4: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[3]);
			printf("Hu Moment hu5: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[4]);
			printf("Hu Moment hu6: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[5]);
			printf("Hu Moment hu7: %.12f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * f))[6]);
			f++;
		}
	}
	//na coluna, pegar o valor max e min, depois pra cada valor da coluna, fazer (valor-min)/(max-min)

	l = 20;
	//teste
	for (t = 1; t < 5; t++) {
		for (j = 1; j < 6; j++) {
			//carrega imagens de treinamento
			char caminho[20];
			char a;
			a = t + 48;
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
			((double*) (testVectors->data.db + testVectors->step * l))[0] = HuMoments.hu1;
			((double*) (testVectors->data.db + testVectors->step * l))[1] = HuMoments.hu2;
			((double*) (testVectors->data.db + testVectors->step * l))[2] = HuMoments.hu3;
			((double*) (testVectors->data.db + testVectors->step * l))[3] = HuMoments.hu4;
			((double*) (testVectors->data.db + testVectors->step * l))[4] = HuMoments.hu5;
			((double*) (testVectors->data.db + testVectors->step * l))[5] = HuMoments.hu6;
			((double*) (testVectors->data.db + testVectors->step * l))[6] = HuMoments.hu7;
			l++;
		}
	}
	//================================================================================
	printf("\nsoma: %f\n", ((double*) (testVectors->data.db + testVectors->step * 23))[0]);
	printf("\nsoma: %f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * 3))[0]);
	/*
	 ======================================KNN===========================================
	 */

	//vetor de classes para teste
	for (i = 40; i < 40+NOI; i++)
	{
		if ((0 <= i) && (i < 5))
			CV_MAT_ELEM( *testClasses, double, 0,i ) = 1;

		if ((5 <= i) && (i < 10))
			CV_MAT_ELEM( *testClasses, double, 0,i ) = 2;

		if ((10 <= i) && (i < 15))
			CV_MAT_ELEM( *testClasses, double, 0,i ) = 3;

		if ((15 <= i) && (i < 20))
			CV_MAT_ELEM( *testClasses, double, 0,i ) = 4;
	}



	//faz matriz de classes para o treinamento
	for (i = 60; i < 60+NOI; i++)
	{
		for (j = 0; j < NOI; j++)
		{
			if ((0 <= j) && (j < 5))
				((double*)trainingClasses->data.db + trainingClasses->step * i)[j] = 1;
			if ((5 <= j) && (j < 10))
				((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] = 2;
			if ((10 <= j) && (j < 15))
				((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] = 3;
			if ((15 <= j) && (j < 20))
				((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] = 4;
		}
	}

	printf("\nsoma...: %f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * 3))[0]);

	//Distancia euclidiana
	for (r = 20; r < 40; r++) {
		printf("\nsomaOI: %f\n", ((double*) (testVectors->data.db + testVectors->step * r))[0]);
		for (q = 0; q < 20; q++)
		{
			for (p = 0; p < 7; p++)
			{
				soma += pow(((double*)(testVectors->data.db+ testVectors->step * r))[p] - ((double*)(trainingVectors->data.db+ trainingVectors->step * q))[p], 2);
			}
			distancia = sqrtf(soma);
			((double*)(DistanceVectors->data.db + DistanceVectors->step * r))[q] =distancia;
			soma = 0;
		}
		//ordena vetor de distancias[q] e o trainingClasses[q]
		//selection(DistanceVectors,trainingClasses,0, 6, q);
	}
	printf("\nsoma: %f\n", ((double*) (trainingVectors->data.db + trainingVectors->step * 3))[0]);
	//encontramos a classe pelos k primeiros
	for (i = 60; i < 80; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] == 1)
				cls1 += 1;
			if (((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] == 2)
				cls2 += 1;
			if (((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] == 3)
				cls3 += 1;
			if (((double*) (trainingClasses->data.db + trainingClasses->step * i))[j] == 4)
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
			cls = CV_MAT_ELEM( *trainingClasses, double, i, 1);
		cls1 = 0, cls2 = 0, cls3 = 0, cls4 = 0; // zera as classes
		CV_MAT_ELEM( *ResultVector, double, 0, j ) = cls;
	}

	/*
	 //compara resultados
	 for (i=0;i<NOI;i++)
	 {
	 if (CV_MAT_ELEM( *ResultVector, double, 0, j ) ==  CV_MAT_ELEM( *testClasses, double, 0, j ))
	 correct += 1;
	 if (CV_MAT_ELEM( *ResultVector, double, 0, j ) !=  CV_MAT_ELEM( *testClasses, double, 0, j ))
	 erros += 1;
	 }


	 //======================================================================================================================================================

	 printf("Time: %d\nAccuracy: %f\n\n", (int)time, (double)correct*100/(double)NOI);

	 //cvReleaseImage( &img_8uc1 );*/

	cvWaitKey(0);
	return 0;

}

