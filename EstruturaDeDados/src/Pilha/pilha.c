#include <stdio.h>

struct Pilha {
	int Valor;
	struct Pilha* prox;
};

struct Pilha* topo = NULL;

void inserir(int Valor) {
	struct Pilha* next;
	next = calloc(1, sizeof(struct Pilha));
	next[0].Valor = Valor;
//next[0].prox=NULL;
	next[0].prox = &topo[0];
//printf("%d\n",&topo[0]);
	topo = next;
//topo[0].prox = &next[0];
}

void remover() {
	struct Pilha* aux;
	aux = topo->prox;
	//topo->prox = NULL;
	free(topo);
	topo = aux;
}
void listar() {
	struct Pilha* aux = topo;
	while (aux[0].prox != 0) {
		printf("%d\n", aux[0].Valor);
		aux = aux[0].prox;
	}
	if (aux[0].prox == 0) {
		printf("%d\n", aux[0].Valor);
	}
}
int main() {
	topo = NULL;
//topo[0].prox=NULL;
//topo=(struct Pilha *)calloc(1,sizeof(struct Pilha));
	inserir(10);
	inserir(20);
	inserir(30);
	printf("Topo: %x Valor Topo: %d\n", &topo, topo->Valor);
	listar();
	remover();
	printf("Removendo topo\n");
	listar();
// topo.Valor=10;
	return 0;
}
