/*Alunos:
Gabriela Barbieri
Juliano Araujo
Luis Henrique*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //0/1 false/true

#define capacidade 7 // Limite máximo de aviões na fila.

typedef struct Aviao
{
  int id;
  int combustivel;
} Aviao;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila
{
  Aviao *aviao;
  PtrNoFila proximo;
} NoFila;

typedef struct Fila
{
  PtrNoFila inicio;
  PtrNoFila fim;
  int qtdElementos;
} Fila;

typedef struct Pista
{
  int pista_esta_disponivel; // 1 se a pista está disponível, 0 caso contrário
  int semaforo;              // 0 - Decolagem; 1 - Aterrisagem fila 1; 2 - Aterrisagem pista 2
  Fila *filaDecolagem;
  Fila *filasAterrisagem[2]
} Pista;

typedef struct Aeroporto
{
  Pista *pistas[3];
} Aeroporto;

Aviao *criarAviao(int id, int comb)
{
  Aviao *aviao = malloc(sizeof(Aviao));

  aviao->id = id;

  if (comb != -1)
    aviao->combustivel = comb;

  return aviao;
}

void inicializarFila(Fila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->qtdElementos = 0;
}

bool estaVaziaFilaDinamica(Fila *f)
{
  return (f->inicio == NULL);
}

int tamanhoFilaDinamica(Fila *f)
{
  return f->qtdElementos;
}

void adicionarAviao(Fila *fila, Aviao *aviao)
{
  PtrNoFila aux = malloc(sizeof(NoFila));
  aux->aviao = aviao;
  aux->proximo = NULL;

  if (estaVaziaFilaDinamica(fila))
  {
    fila->inicio = aux;
  }
  else
  {
    fila->fim->proximo = aux;
  }

  fila->fim = aux;
  fila->qtdElementos++;
}

Aviao *inicioFilaDinamica(Fila *f)
{
  Aviao *ret = NULL;

  if (!estaVaziaFilaDinamica(f))
  {
    ret = f->inicio->aviao;
  }

  return ret;
}

Aviao *fimFilaDinamica(Fila *f)
{
  Aviao *ret = NULL;

  if (!estaVaziaFilaDinamica(f))
  {
    ret = f->fim->aviao;
  }

  return ret;
}

Aviao *removerFilaDinamica(Fila *f)
{
  if (!estaVaziaFilaDinamica(f))
  {
    PtrNoFila aux;
    aux = f->inicio;
    f->inicio = f->inicio->proximo;
    free(aux);
    f->qtdElementos--;

    return aux->aviao;
  }

  else
  {
    return NULL;
  }
}

PtrNoFila *navegarFila(PtrNoFila no)
{
  return no->proximo;
}

Aeroporto *inicializarAeroporto()
{
  Aeroporto *aeroporto = malloc(sizeof(Aeroporto));

  // Criar e alocar as pistas
  for (int i = 1; i <= 3; i++)
  {
    Pista *pista = malloc(sizeof(Pista));
    pista->pista_esta_disponivel = 1;
    pista->semaforo = 0;

    // Cria fila de decolagem
    Fila *decolagem = malloc(sizeof(Fila));
    pista->filaDecolagem = decolagem;

    // Criar filas de pouso
    if (i != 3)
    {
      Fila *filaPouso1 = malloc(sizeof(Fila));
      Fila *filaPouso2 = malloc(sizeof(Fila));

      pista->filasAterrisagem[0] = filaPouso1;
      pista->filasAterrisagem[1] = filaPouso2;
    }

    aeroporto->pistas[i] = pista;
  }

  return aeroporto;
}

void imprimirFila(Fila *f)
{
  for (PtrNoFila i = f->inicio; i != NULL; i = navegarFila(i))
  {
    Aviao *aviao = i->aviao;

    int id = aviao->id;
    int combustivel = aviao->combustivel;

    printf("(ID: %d - combustivel: %d) ", id, combustivel);
  }
}

void imprimirPista(Pista *pista)
{
  Fila *decolagem = pista->filaDecolagem;
  Fila **aterrisagem = pista->filasAterrisagem;

  printf("Fila de decolagem: ");
  imprimirFila(decolagem);
  printf("/n");

  if (aterrisagem[0] == NULL)
    return;

  printf("Fila de aterrisagem 1: ");
  imprimirFila(aterrisagem[0]);
  printf("/n");

  printf("Fila de aterrisagem 2: ");
  imprimirFila(aterrisagem[1]);
  printf("/n");
}

void imprimirAeroporto(Aeroporto *aeroporto)
{
  Pista **pistas = aeroporto->pistas;

  for (int i = 0; i < 3; i++)
  {
    Pista *pista = pistas[i];

    printf("Pista %d:\n", i);
    imprimirPista(pista);

    printf("\n");
  }
}

int totalTempo = 0;
int totalDecolagens = 0;
int totalAterrissagens = 0;
int totalSemCombustivel = 0;

void imprimirEstatiscas()
{
  printf("Estatisticas:\n");
  printf("Tempo medio para decolagem: %f\n", (float)totalTempo / totalDecolagens);
  printf("Tempo medio para aterrissagem: %f\n", (float)totalTempo / totalAterrissagens);
  printf("Avioes que pousaram praticamente sem combustivel: %d\n", totalSemCombustivel);
}

void reduzirCombustivel(Pista *pista)
{
  // Retirar combustivel dos aviões restantes da fila
  Fila *filaDecolagem = pista->filaDecolagem;
  Fila *filaAterrisagem1 = pista->filasAterrisagem[0];
  Fila *filaAterrisagem2 = pista->filasAterrisagem[1];

  for (PtrNoFila i = filaDecolagem->inicio; i != NULL; i = navegarFila(i))
  {
    i->aviao->combustivel--;
  }

  for (PtrNoFila i = filaAterrisagem1->inicio; i != NULL; i = navegarFila(i))
  {
    i->aviao->combustivel--;
  }

  for (PtrNoFila i = filaAterrisagem2->inicio; i != NULL; i = navegarFila(i))
  {
    i->aviao->combustivel--;
  }
}

void processarDecolagensAterrisagens(Pista *pista)
{

  // PULO A PISTA DEVIDO A UM POUSO DE EMERGENCIA
  if (pista->pista_esta_disponivel == 0)
  {
    pista->pista_esta_disponivel = 1;
    return;
  }

  int semaforo = pista->semaforo;
  Fila *fila;

  if (semaforo == 0)
  {
    fila = pista->filaDecolagem;
  }
  else if (semaforo == 1)
  {
    fila = pista->filasAterrisagem[0];
  }
  else if (semaforo == 2)
  {
    fila = pista->filasAterrisagem[1];
  }

  removerFilaDinamica(fila);

  semaforo++;

  if (semaforo > 2)
  {
    semaforo = 0;
  }
}

void verificarPousoDeEmergencia(Aeroporto *aeroporto)
{
  for (int i = 0; i < 2; i++)
  {
    Pista *pista = aeroporto->pistas[i];
    Fila *filaAterrisagem1 = pista->filasAterrisagem[0];
    Fila *filaAterrisagem2 = pista->filasAterrisagem[1];

    PtrNoFila noAnterior = NULL;
    for (PtrNoFila i = filaAterrisagem1->inicio; i != NULL; i = navegarFila(i))
    {
      if (i->aviao->combustivel == 0)
      {

        if (aeroporto->pistas[2]->pista_esta_disponivel == 1)
        {
          aeroporto->pistas[2]->pista_esta_disponivel = 0;
        }
        else if (aeroporto->pistas[1]->pista_esta_disponivel == 1)
        {
          aeroporto->pistas[1]->pista_esta_disponivel = 0;
        }
        else if (aeroporto->pistas[0]->pista_esta_disponivel == 1)
        {
          aeroporto->pistas[0]->pista_esta_disponivel = 0;
        }
        else
        {
          printf("O avião %d caiu por falta de combustível", i->aviao->id);
        }

        // logica da Fila
        PtrNoFila proximoNo = i->proximo;

        if (noAnterior == NULL)
        {
          filaAterrisagem1->inicio = proximoNo;
        }
        else
        {
          noAnterior->proximo = proximoNo;
        }
      }

      noAnterior = i;
    }

    for (PtrNoFila i = filaAterrisagem2->inicio; i != NULL; i = navegarFila(i))
    {

      if (aeroporto->pistas[2]->pista_esta_disponivel == 1)
      {
        aeroporto->pistas[2]->pista_esta_disponivel = 0;
      }
      else if (aeroporto->pistas[1]->pista_esta_disponivel == 1)
      {
        aeroporto->pistas[1]->pista_esta_disponivel = 0;
      }
      else if (aeroporto->pistas[0]->pista_esta_disponivel == 1)
      {
        aeroporto->pistas[0]->pista_esta_disponivel = 0;
      }
      else
      {
        printf("O avião %d caiu por falta de combustível", i->aviao->id);
      }

      // logica da Fila
      PtrNoFila proximoNo = i->proximo;

      if (noAnterior == NULL)
      {
        filaAterrisagem2->inicio = proximoNo;
      }
      else
      {
        noAnterior->proximo = proximoNo;
      }
    }

    noAnterior = i;
  }
}

void processarTempo(Aeroporto *aeroporto, int avioesDecolagem, int avioesAterrisagem, int *combustivel)
{
  // Avioes chegam

  int idDecolagem = 1;
  for (int i = 0; i < avioesDecolagem; i++)
  {
    Aviao *aviao = criarAviao(idDecolagem++ * 2, -1);

    int menor = -1;
    int pista = -1;
    for (int j = 0; j < 3; j++)
    {
      Pista *pista = aeroporto->pistas[j];
      Fila *fila = pista->filaDecolagem;

      int tamanho = tamanhoFilaDinamica(fila);

      if (pista == -1 || tamanho < menor)
      {
        menor = tamanho;
        pista = j;
      }
    }

    Fila *filaAdicao = aeroporto->pistas[pista]->filaDecolagem;

    adicionarAviao(filaAdicao, aviao);
  }

  int idAterrisagem = 1;
  for (int i = 0; i < avioesAterrisagem; i++)
  {
    Aviao *aviao = criarAviao(idAterrisagem++ * 2 - 1, combustivel[i]);

    int idDecolagem = 1;
    for (int i = 0; i < avioesDecolagem; i++)
    {
      Aviao *aviao = criarAviao(idDecolagem++ * 2, -1);

      int menor = -1;
      int pista = -1;
      int fila = -1;

      for (int j = 0; j < 3; j++)
      {
        Pista *pista = aeroporto->pistas[j];

        for (int k = 0; k < 2; k++)
        {
          Fila *fila = pista->filasAterrisagem[k];
          int tamanho = tamanhoFilaDinamica(fila);

          if (pista == -1 || tamanho < menor)
          {
            menor = tamanho;
            pista = j;
            fila = k;
          }
        }
      }

      Fila *filaAdicao = aeroporto->pistas[pista]->filasAterrisagem[fila];
      adicionarAviao(filaAdicao, aviao);
    }
  }

    // POUSO EMERGENCIA

    verificarPousoDeEmergencia(aeroporto);

    // PROCESSAR AS PISTAS

    for (int i = 0; i < 3; i++)
    {
      Pista *pista = aeroporto->pistas[i];
      processarDecolagensAterrisagens(pista);
    }

    imprimirAeroporto(aeroporto);
    imprimirEstatiscas();
  }

int main(int argc, const char * argv[]) {

// verifica se o usuário passou o número correto de parâmetros
  if (argc != 2) {
    printf("Voce nao passou o numero certo de parametros!");

    exit(10);
  }

    // abre os arquivos de acordo como os parâmetros fornecidos
    FILE *arquivo_entrada = fopen(argv[1], "r");

    if (arquivo_entrada == NULL)
    {
      printf("Erro ao abrir o arquivo!");
      exit(1);
    }

    int retorno;
    int numDecolagem = 0;
    int numAterrisagem = 0;
    int combAterrisagem[3];

    Aeroporto *aeroporto = inicializarAeroporto();

    while (true)
    {
      retorno = fscanf(arquivo_entrada, "%d; %d %d %d %d", &numDecolagem, &numAterrisagem, &combAterrisagem[0], &combAterrisagem[1], &combAterrisagem[2]);

      if (retorno == EOF)
        break;

      processarTempo(aeroporto, numDecolagem, numAterrisagem, combAterrisagem);
    }

    return 0;
  }

  /*Complexidade do problema: O(n^4) */
