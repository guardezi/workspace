/*
 * knn.c
 *
 *  Created on: Nov 16, 2012 06:04
 *      Author: guardezi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct distancia {
	float resultado;
	int rotulo;
};

struct classe {
	int nome;
	float caracteristicas[200];
	struct distancia distancias[1000];
	int votos[10];
};

struct classe treino[1000];
struct classe teste[1000];
int val[100][100];
float maiorv, menorv;
void classificar(int l, int k, int n) {
	int i, maior;
	for (i = 0; i < 10; i++)
		teste[l].votos[i] = 0;

	for (i = 0; i < k; i++)
		teste[l].votos[teste[l].distancias[i].rotulo]++;

	maior = 0;
	for (i = 1; i < 10; i++)
		if (teste[l].votos[i] > teste[l].votos[maior])
			maior = i;

	val[teste[l].nome][maior]++;
}

//troca no metodo de ordenaçao
void troca(int l, int i, int j) {
	struct distancia aux;
	aux.resultado = teste[l].distancias[i].resultado;
	aux.rotulo = teste[l].distancias[i].rotulo;
	teste[l].distancias[i].resultado = teste[l].distancias[j].resultado;
	teste[l].distancias[i].rotulo = teste[l].distancias[j].rotulo;
	teste[l].distancias[j].resultado = aux.resultado;
	teste[l].distancias[j].rotulo = aux.rotulo;
}

//Metodo quick sort
int partition(int left, int right, int l) {
	int i, j;
	i = left;
	for (j = left + 1; j <= right; ++j) {
		if (teste[l].distancias[j].resultado
				< teste[l].distancias[left].resultado) {
			++i;
			troca(l, i, j);
		}
	}
	troca(l, left, i);
	return i;
}
void quickSort(int left, int right, int l) {
	int r;

	if (right > left) {
		r = partition(left, right, l);
		quickSort(left, r - 1, l);
		quickSort(r + 1, right, l);
	}
}

//Metodo de ordenação Buble sort
void ordenar(int n, int l) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (teste[l].distancias[i].resultado
					> teste[l].distancias[j].resultado)
				troca(l, i, j);

}

//Calcula distancia entre os pontos
void calcDist(int n, int k, int l) {
	int i, j;
	float soma;
	for (i = 0; i < n; i++) {
		soma = 0;
		for (j = 0; j < k; j++) {
			soma +=
					pow(
							(teste[l].caracteristicas[j]
									- treino[i].caracteristicas[j]), 2);
		}
		teste[l].distancias[i].resultado = sqrt(soma);
		teste[l].distancias[i].rotulo = treino[i].nome;
	}
//	ordenar(n,l);
	quickSort(0, n - 1, l);
}

//Carregar base de testes
void carregarBaseTeste(int n, int k) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			scanf("%f ", &teste[i].caracteristicas[j]);
			teste[i].caracteristicas[j] = (teste[i].caracteristicas[j]- menorv )/ (maiorv - menorv);
			if(teste[i].caracteristicas[j]>1)
				teste[i].caracteristicas[j]=1;
			if(teste[i].caracteristicas[j]<0)
				teste[i].caracteristicas[j]=0;
		}
		scanf("%i", &teste[i].nome);
	}
}

//	Carregar Base de treinamento
void treinamento(int n, int k) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			scanf("%f", &treino[i].caracteristicas[j]);
			if (i == 0 && j == 0)
				maiorv = menorv = treino[i].caracteristicas[j];
			else {
				if (treino[i].caracteristicas[j] > maiorv)
					maiorv = treino[i].caracteristicas[j];
				if (treino[i].caracteristicas[j] < menorv)
					menorv = treino[i].caracteristicas[j];
			}
		}
		scanf("%i", &treino[i].nome);
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			treino[i].caracteristicas[j] = (treino[i].caracteristicas[j] - menorv) / (maiorv - menorv);
		}
	}
}

void visualizar(int n) {
	int i, j, cMin, cMax;
	cMax = treino[0].nome;
	cMin = treino[0].nome;
	for (i = 1; i < n; i++) {
		if (treino[i].nome > cMax)
			cMax = treino[i].nome;
		if (treino[i].nome < cMin)
			cMin = treino[i].nome;
	}
	float acerto = 0;
	for (i = cMin; i <= cMax; i++)
		printf("\t%i", i);
	printf("\n");
	for (i = cMin; i <= cMax; i++) {
		printf("%i", i);
		for (j = cMin; j <= cMax; j++) {
			printf("\t%i ", val[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i <= n; i++) {
		acerto += val[i][i];
	}
	printf("Reconhecimento %.2f por cento\n", ((acerto / n) * 100));
}

int main() {
	int n, k, i, nt, kt, v;
//	numero de caracteriscas para votar
	scanf("%i", &v);
//	numero de linhas do
	scanf("%i", &n);
	scanf("%i", &k);
	treinamento(n, k);
	scanf("%i", &nt);
	scanf("%i", &kt);
	carregarBaseTeste(nt, kt);

	for (i = 0; i < nt; i++) {
		calcDist(n, k, i);
		classificar(i, v, n);
	}
	visualizar(nt);

	return 1;
}