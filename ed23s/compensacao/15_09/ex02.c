#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //0/1 false/true

typedef struct NoPilha *PtrNoPilha;

struct NoPilha
{
	int elemento;
	PtrNoPilha proximo;
} NoPilha;

typedef struct
{
	PtrNoPilha topo;
	int tamanho;
} PilhaDinamica;

void iniciaPilhaDinamica(PilhaDinamica *p)
{
	p->tamanho = 0;
	p->topo = NULL;
}

bool estaVaziaPilhaDinamica(PilhaDinamica *p)
{
	return (p->topo == NULL);
}

int tamanhoPilhaDinamica(PilhaDinamica *p)
{
	return (p->tamanho);
}

void imprimirPilhaDinamica(PilhaDinamica *p)
{
	printf("Pilha = [");
	PtrNoPilha aux;
	for (aux = p->topo; aux != NULL; aux = aux->proximo)
	{
		printf("%d ", aux->elemento);
	}
	printf("]\n");
}

void inserirPilhaDinamica(PilhaDinamica *p, int num)
{
	PtrNoPilha aux = malloc(sizeof(NoPilha));
	aux->elemento = num;
	aux->proximo = p->topo;
	p->topo = aux;
	p->tamanho++;
}

void removerPilhaDinamica(PilhaDinamica *p)
{
	if (!estaVaziaPilhaDinamica(p))
	{
		PtrNoPilha aux;
		aux = p->topo;
		p->topo = p->topo->proximo;
		free(aux);
		p->tamanho--;
	}
	else
	{
		printf("Warning: pilha esta vazia!\n");
	}
}

void limparPilhaDinamica(PilhaDinamica *p)
{
	if (!estaVaziaPilhaDinamica(p))
	{
		PtrNoPilha aux = p->topo;
		int tamanho = tamanhoPilhaDinamica(p);

		for (int i = 0; i < tamanho; i++)
		{
			PtrNoPilha proximo = aux->proximo;
			free(aux);
			aux = proximo;
		}

		p->tamanho = 0;
		p->topo = NULL;
	}
}

int main()
{
	PilhaDinamica pilha;
	iniciaPilhaDinamica(&pilha);

	// Inserindo alguns elementos
	inserirPilhaDinamica(&pilha, 6);
	inserirPilhaDinamica(&pilha, 10);
	inserirPilhaDinamica(&pilha, 2);
	inserirPilhaDinamica(&pilha, 7);

	imprimirPilhaDinamica(&pilha);

	// como a pilha vai ser limpa várias vezes essa função deixa mais rápida a limpeza fazendo menos operações
	limparPilhaDinamica(&pilha);

	imprimirPilhaDinamica(&pilha);

	return 0;
}