#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NoArvore *PtrNoArvore;

typedef struct NoArvore
{
  int chave;
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;

// ---------------------------------------
// ---------------------------------------

// destruicao
// remover
// pesquisar
// maximo (int) * | rec | iterativo (while)
// minimo (int) * | rec | iterativo (while)
// tamanho (int) *
// percurso (em ordem, pre ordem, pos Ordem)
// ---------------------------------------
// ---------------------------------------
void iniciaArvoreBinaria(PtrNoArvore *r)
{
  (*r) = NULL;
}

bool estaVaziaArvoreBinaria(PtrNoArvore *r)
{
  return ((*r) == NULL);
}

bool inserirArvoreBinaria(PtrNoArvore *no, int valor)
{
  if ((*no) == NULL)
  {
    (*no) = malloc(sizeof(NoArvore));
    (*no)->chave = valor;

    (*no)->direita = NULL;
    (*no)->esquerda = NULL;
    return (true);
  }

  if ((*no)->chave == valor)
    return (false);

  if (valor > (*no)->chave)
  {
    return (inserirArvoreBinaria(&(*no)->direita, valor));
  }
  else
  {
    return (inserirArvoreBinaria(&(*no)->esquerda, valor));
  }
}

void PreOrdemArvoreBinaria(PtrNoArvore *no)
{
  if ((*no) == NULL)
    return;

  printf("%d ", (*no)->chave);
  PreOrdemArvoreBinaria(&(*no)->esquerda);
  PreOrdemArvoreBinaria(&(*no)->direita);
}

void PreOrdemPrincipal(PtrNoArvore *no)
{
  printf("PreOrdem = { ");
  PreOrdemArvoreBinaria(&(*no));
  printf("}\n");
}

void EmOrdemArvoreBinaria(PtrNoArvore *no)
{
  if ((*no) == NULL)
    return;

  EmOrdemArvoreBinaria(&(*no)->esquerda);
  printf("%d ", (*no)->chave);
  EmOrdemArvoreBinaria(&(*no)->direita);
}

void EmOrdemPrincipal(PtrNoArvore *no)
{
  printf("EmOrdem = { ");
  EmOrdemArvoreBinaria(&(*no));
  printf("}\n");
}

void EmOrdemDecrescenteArvoreBinaria(PtrNoArvore *no)
{
  if ((*no) == NULL)
    return;

  EmOrdemDecrescenteArvoreBinaria(&(*no)->direita);
  printf("%d ", (*no)->chave);
  EmOrdemDecrescenteArvoreBinaria(&(*no)->esquerda);
}

void MostraChavesDecrescentes(PtrNoArvore *no)
{
  printf("EmOrdem Decrescent = { ");
  EmOrdemDecrescenteArvoreBinaria(&(*no));
  printf("}\n");
}

void PosOrdemArvoreBinaria(PtrNoArvore *no)
{
  if ((*no) == NULL)
    return;

  PosOrdemArvoreBinaria(&(*no)->esquerda);
  PosOrdemArvoreBinaria(&(*no)->direita);
  printf("%d ", (*no)->chave);
}

void PosOrdemPrincipal(PtrNoArvore *no)
{
  printf("PosOrdem = { ");
  PosOrdemArvoreBinaria(&(*no));
  printf("}\n");
}

bool pesquisaArvoreBinaria(PtrNoArvore *no, int valor)
{
  if ((*no) == NULL)
    return false;

  if ((*no)->chave == valor)
    return (true);

  if (valor > (*no)->chave)
  {
    return (pesquisaArvoreBinaria(&(*no)->direita, valor));
  }
  else
  {
    return (pesquisaArvoreBinaria(&(*no)->esquerda, valor));
  }
}

PtrNoArvore pegarMaiorElemento(PtrNoArvore *no)
{
  while ((*no)->direita != NULL)
  {
    (*no) = (*no)->direita;
  }

  PtrNoArvore ret = (*no);
  return (ret);
}

bool removerArvoreBinaria(PtrNoArvore *no, int valor)
{
  if ((*no) == NULL)
    return false;

  if ((*no)->chave == valor)
  {
    PtrNoArvore rm = (*no);

    if ((*no)->esquerda == NULL && (*no)->direita != NULL)
    {
      (*no) = (*no)->direita;
    }

    else if ((*no)->direita == NULL && (*no)->esquerda == NULL)
    {
      (*no) = NULL;
    }

    else if ((*no)->esquerda != NULL && (*no)->direita == NULL)
    {
      (*no) = (*no)->esquerda;
    }

    else
    {
      rm = pegarMaiorElemento(&(*no)->esquerda);
      (*no)->chave = rm->chave;
    }

    free(rm);

    return true;
  }

  if (valor > (*no)->chave)
  {
    return (removerArvoreBinaria(&(*no)->direita, valor));
  }
  else
  { // <
    return (removerArvoreBinaria(&(*no)->esquerda, valor));
  }
}

int main(int argc, const char *argv[])
{
  PtrNoArvore raiz;

  iniciaArvoreBinaria(&raiz);

  inserirArvoreBinaria(&raiz, 30);
  inserirArvoreBinaria(&raiz, 44);
  inserirArvoreBinaria(&raiz, 23);
  inserirArvoreBinaria(&raiz, 47);
  inserirArvoreBinaria(&raiz, 39);
  inserirArvoreBinaria(&raiz, 29);
  inserirArvoreBinaria(&raiz, 52);
  inserirArvoreBinaria(&raiz, 38);

  MostraChavesDecrescentes(&raiz);

  return 0;
}