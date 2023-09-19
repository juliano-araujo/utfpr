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

  // limpando a pilha e liberando memória fazendo várias chamadas
  while (estaVaziaPilhaDinamica(&pilha) == false)
  {
    removerPilhaDinamica(&pilha);
  }

  imprimirPilhaDinamica(&pilha);

  return 0;
}