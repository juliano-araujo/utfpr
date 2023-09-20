/*Alunos:
Gabriela Barbieri
Juliano Araujo
Luis Henrique*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //0/1 false/true

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
  int possuiAterrisagem;     // 1 sim, 0 nao
  Fila *filaDecolagem;
  Fila *filasAterrisagem[2];
} Pista;

typedef struct Aeroporto
{
  Pista *pistas[3];
} Aeroporto;

Aviao *criarAviao(int id, int comb)
{
  Aviao *aviao = malloc(sizeof(Aviao));

  aviao->id = id;
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

PtrNoFila navegarFila(PtrNoFila no)
{
  return no->proximo;
}

Aeroporto *inicializarAeroporto()
{
  Aeroporto *aeroporto = (Aeroporto *)malloc(sizeof(Aeroporto));

  // Criar e alocar as pistas
  for (int i = 1; i <= 3; i++)
  {
    Pista *pista = (Pista *)malloc(sizeof(Pista));
    pista->pista_esta_disponivel = 1;
    pista->semaforo = 0;

    // Cria fila de decolagem
    Fila *decolagem = (Fila *)malloc(sizeof(Fila));
    inicializarFila(decolagem);
    pista->filaDecolagem = decolagem;

    pista->possuiAterrisagem = 0;

    // Criar filas de pouso
    if (i != 3)
    {
      Fila *filaPouso1 = (Fila *)malloc(sizeof(Fila));
      inicializarFila(filaPouso1);
      Fila *filaPouso2 = (Fila *)malloc(sizeof(Fila));
      inicializarFila(filaPouso2);

      pista->filasAterrisagem[0] = filaPouso1;
      pista->filasAterrisagem[1] = filaPouso2;

      pista->possuiAterrisagem = 1;
    }

    aeroporto->pistas[i - 1] = pista;
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

    printf("(ID: %d", id);

    if (combustivel != -1)
    {
      printf(" - combustivel: %d", combustivel);
    }

    printf(") ");
  }
}

void imprimirPista(Pista *pista)
{
  Fila *decolagem = pista->filaDecolagem;
  Fila **aterrisagem = pista->filasAterrisagem;

  printf("Fila de decolagem: ");
  imprimirFila(decolagem);
  printf("\n");

  if (aterrisagem[0] == NULL)
    return;

  printf("Fila de aterrisagem 1: ");
  imprimirFila(aterrisagem[0]);
  printf("\n");

  printf("Fila de aterrisagem 2: ");
  imprimirFila(aterrisagem[1]);
  printf("\n");
}

void imprimirAeroporto(Aeroporto *aeroporto)
{
  Pista **pistas = aeroporto->pistas;

  for (int i = 0; i < 3; i++)
  {
    Pista *pista = pistas[i];

    printf("Pista %d:\n", i + 1);
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

  printf("total %d\n", totalAterrissagens);

  float mediaDecolagens = totalDecolagens > 0 ? (float)totalTempo / totalDecolagens : 0;
  float mediaAterrissagens = totalAterrissagens > 0 ? (float)totalTempo / totalAterrissagens : 0;

  printf("Estatisticas:\n");
  printf("Tempo medio para decolagem: %f\n", mediaDecolagens);
  printf("Tempo medio para aterrissagem: %f\n", mediaAterrissagens);
  printf("Avioes que pousaram praticamente sem combustivel: %d\n\n", totalSemCombustivel);
}

void reduzirCombustivel(Pista *pista)
{
  // Retirar combustivel dos aviões restantes da fila
  Fila *filaAterrisagem1 = pista->filasAterrisagem[0];
  Fila *filaAterrisagem2 = pista->filasAterrisagem[1];

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

  Fila *fila;

  if (pista->possuiAterrisagem == 0)
  {
    fila = pista->filaDecolagem;
    totalDecolagens++;
  }
  else
  {
    int semaforo = pista->semaforo;

    if (semaforo == 0)
    {
      fila = pista->filaDecolagem;
      totalDecolagens++;
    }
    else if (semaforo == 1)
    {
      fila = pista->filasAterrisagem[0];
      totalAterrissagens++;
    }
    else if (semaforo == 2)
    {
      fila = pista->filasAterrisagem[1];
      totalAterrissagens++;
    }

    semaforo++;

    if (semaforo > 2)
    {
      semaforo = 0;
    }

    pista->semaforo = semaforo;
  }

  removerFilaDinamica(fila);
}

void verificarPousoDeEmergencia(Aeroporto *aeroporto)
{
  for (int i = 0; i < 2; i++)
  {
    Pista *pista = aeroporto->pistas[i];
    Fila *filaAterrisagem1 = pista->filasAterrisagem[0];
    Fila *filaAterrisagem2 = pista->filasAterrisagem[1];

    PtrNoFila noAnterior = NULL;
    for (PtrNoFila j = filaAterrisagem1->inicio; j != NULL; j = navegarFila(j))
    {
      if (j->aviao->combustivel == 0)
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
          printf("O avião %d caiu por falta de combustível", j->aviao->id);
        }

        // logica da Fila
        PtrNoFila proximoNo = j->proximo;

        if (noAnterior == NULL)
        {
          filaAterrisagem1->inicio = proximoNo;
        }
        else
        {
          noAnterior->proximo = proximoNo;
        }
      }

      noAnterior = j;
    }

    for (PtrNoFila j = filaAterrisagem2->inicio; j != NULL; j = navegarFila(j))
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
        printf("O avião %d caiu por falta de combustível", j->aviao->id);
      }

      // logica da Fila
      PtrNoFila proximoNo = j->proximo;

      if (noAnterior == NULL)
      {
        filaAterrisagem2->inicio = proximoNo;
      }
      else
      {
        noAnterior->proximo = proximoNo;
      }

      noAnterior = j;
    }
  }
}

bool possuiAvioesNasFilas(Aeroporto *aeroporto)
{

  bool retorno = false;
  for (int i = 0; i < 3; i++)
  {
    Pista *pista = aeroporto->pistas[i];

    Fila *filaDecolagem = pista->filaDecolagem;

    if (tamanhoFilaDinamica(filaDecolagem) > 0)
    {
      retorno = true;
      break;
    }

    if (pista->possuiAterrisagem)
    {
      Fila *filaAterrissagem1 = pista->filasAterrisagem[0];

      if (tamanhoFilaDinamica(filaAterrissagem1) > 0)
      {
        retorno = true;
        break;
      }

      Fila *filaAterrissagem2 = pista->filasAterrisagem[1];

      if (tamanhoFilaDinamica(filaAterrissagem2) > 0)
      {
        retorno = true;
        break;
      }
    }
  }

  return retorno;
}

int idDecolagem = 1;
int idAterrisagem = 1;
void processarTempo(Aeroporto *aeroporto, int avioesDecolagem, int avioesAterrisagem, int combustivel[3])
{
  // Avioes chegam

  if (avioesDecolagem > 0)
  {
    for (int i = 0; i < avioesDecolagem; i++)
    {
      Aviao *aviao = criarAviao(idDecolagem++ * 2, -1);

      int menor = -1;
      int numPista = -1;

      for (int j = 0; j < 3; j++)
      {
        Pista *pista = aeroporto->pistas[j];
        Fila *fila = pista->filaDecolagem;

        int tamanho = tamanhoFilaDinamica(fila);

        if (numPista == -1 || tamanho < menor)
        {
          menor = tamanho;
          numPista = j;
        }
      }

      Fila *filaAdicao = aeroporto->pistas[numPista]->filaDecolagem;

      adicionarAviao(filaAdicao, aviao);
    }
  }

  if (avioesAterrisagem > 0)
  {
    for (int i = 0; i < avioesAterrisagem; i++)
    {
      Aviao *aviao = criarAviao((idAterrisagem++ * 2) - 1, combustivel[i]);

      int menor = -1;
      int numPista = -1;

      int numFila = combustivel[i] < 10 ? 0 : 1;
      for (int j = 0; j < 2; j++)
      {
        Pista *pista = aeroporto->pistas[j];
        Fila *fila = pista->filasAterrisagem[numFila];

        int tamanho = tamanhoFilaDinamica(fila);

        if (numPista == -1 || tamanho < menor)
        {
          menor = tamanho;
          numPista = j;
        }
      }

      Fila *filaAdicao = aeroporto->pistas[numPista]->filasAterrisagem[numFila];

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

    if (i == 2)
      continue;

    reduzirCombustivel(pista);
  }

  // combustível cai com o passar do tempo

  totalTempo++;
  imprimirAeroporto(aeroporto);
  imprimirEstatiscas();

  // return possuiAvioesNasFilas(aeroporto);
}

int main(int argc, char *argv[])
{
  FILE *file;

  // verifica se o usuário passou o número correto de parâmetros
  if (argc != 2)
  {
    printf("Voce nao passou o numero certo de parametros!\n");

    return 10;
  }

  // abre os arquivos de acordo como os parâmetros fornecidos
  file = fopen(argv[1], "r");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    exit(1);
  }

  Aeroporto *aeroporto = inicializarAeroporto();

  int retornoFile = 0;

  int numDecolagem = 0;
  int numAterrisagem = 0;
  int combAterrisagem[3];

  while (true)
  {

    retornoFile = fscanf(file, "%d; %d %d %d %d", &numDecolagem, &numAterrisagem, &combAterrisagem[0], &combAterrisagem[1], &combAterrisagem[2]);

    if (retornoFile == EOF)
    {
      break;
    }

    processarTempo(aeroporto, numDecolagem, numAterrisagem, combAterrisagem);

    if (retornoFile == EOF)
    {
      break;
    }
  }

  return 0;
}

/*Complexidade do problema: O(n^4) */
