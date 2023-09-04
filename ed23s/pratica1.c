#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_PILHA 20

// TAD (Pilha Estatica)
typedef struct {
  // vetor (int)
  int vetor[TAMANHO_PILHA];
  // topo (int) - indexador (guarda o indice de posicoes do vetor)
  int topo;
} PilhaEstatica;

//-----------------------
// Operações
//-----------------------

void inicializarPilhaEstatica(PilhaEstatica *p) { 
  p->topo = 0;
}

bool estaVaziaPilhaEstatica(PilhaEstatica *p) {
  return(p->topo == 0);
}

bool estaCheiaPilhaEstatica(PilhaEstatica *p) {
  return(p->topo == TAMANHO_PILHA);
}

int tamanhoPilhaEstatica(PilhaEstatica *p) {
  return(p->topo);
}

void imprimirPilhaEstatica(PilhaEstatica *p) {
  printf("Pilha = [");

  for(int i = 0; i < p->topo; i++) {
    printf("%d ", p->vetor[i]);
  }

  printf("]\n");
}

// * insercao (empilha/push)
void empilharPilhaEstatica(PilhaEstatica *pilha, int x) {
// se a pilha estiver cheia:
  if(estaCheiaPilhaEstatica(pilha)) {
     printf("Warning: pilha cheia!\n");

     return;
  }

  // se a pilha nao estiver cheia:

  // add o numero (x) na posicao indexada pelo topo
  pilha->vetor[pilha->topo] = x;
 
  //     incrementa o valor do topo
  pilha->topo++;
}

// consulta (topo)
int topoPilhaEstatica(PilhaEstatica *pilha) {
  int ret = pilha->vetor[pilha->topo-1];
 
  return(ret);
}

// remocao (desempilha/pop)
int desempilharPilhaEstatica(PilhaEstatica *pilha) {

  // se a pilha esta vazia:
  if(estaVaziaPilhaEstatica(pilha)){
    printf("Warning: pilha está vazia!\n");
  } else {
    // se a pilha nao esta vazia:

    // copiar o valor do vetor[topo] em um aux
    int ret = topoPilhaEstatica(pilha);
    
    // topo decrementado retornar uma posicao
    pilha->topo--;
    
    // retorna o elemento aux
    return ret;
  }
}

int main(int argc, const char * argv[]) {

// verifica se o usuário passou o número correto de parâmetros
  if (argc != 3) {
    printf("Voce nao passou o numero certo de parametros!");

    exit(10);
  }


  //abre os arquivos de acordo como os parâmetros fornecidos
  FILE *arquivo_entrada = fopen(argv[1], "r");
  
  if (arquivo_entrada == NULL) {
    printf("Erro ao abrir o arquivo!");
    exit(1);
  }
  
  FILE *arquivo_saida = fopen(argv[2], "w");

  if (arquivo_saida == NULL) {
    printf("Erro ao abrir o arquivo!");
    exit(1);
  }

  // inicialização da pilha
  PilhaEstatica pilha;
  inicializarPilhaEstatica(&pilha);

  int numero, retorno;

  // leitura de cada linha do arquivo
  while ((retorno = fscanf(arquivo_entrada, "%d", &numero)) != EOF)
  {

    // verificação de valores inválidos na leitura
    if (retorno != 1) {
      fprintf(arquivo_saida, "Arquivo invalido!");
      exit(11);
    }

    empilharPilhaEstatica(&pilha, numero);
  }

  fclose(arquivo_entrada);

  int tamPilha = tamanhoPilhaEstatica(&pilha);

  // se a pilha estiver vazia no final da operação, o arquivo estava vazio. Esse é o tratamento 
  if (tamPilha == 0) {
    fprintf(arquivo_saida, "Arquivo invalido!");
    exit(10);
  }

  for (int i = 0; i < tamPilha; i++) {
    int num = desempilharPilhaEstatica(&pilha);

    if (num == 0) {
      fprintf(arquivo_saida, "%d", 0);
      
      continue;
    }
    

    //conversao para números binários
    int binario[10];
    int index = 0;

    while (num > 0) {
      /*ex: num = 10. 
      binario[0] = 0
      num = 10 / 2 = 5;
      num = 5. 
      binario[1] = 1
      num = 5 / 2 = 2;
      num = 2. 
      binario[2] = 0
      num = 2 / 2 = 1;
      num = 1;
      binario[3] = 1;
      resultado = 1010
      Basicamente usamos esse código para fazer divisões sucessivas por 2 e achar o valor binário correspondente ao decimal.*/
      binario[index++] = num % 2;
      
      num = num / 2; 
    }

    for (int i = index - 1; i >= 0; i--) {	
	  // imprimir o numero que representa o binario, necessário imprimir de trás para frente. 
      fprintf(arquivo_saida, "%d", binario[i]);
    }
  
    fprintf(arquivo_saida, "\n");
  }

  fclose(arquivo_saida);
  
  return 0;
}
  
