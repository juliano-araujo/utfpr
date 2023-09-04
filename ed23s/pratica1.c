#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_PILHA 20

typedef struct {
  int vetor[TAMANHO_PILHA];
  int topo;
} PilhaEstatica;

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
  printf("Pilha = [ ");

  for(int i = 0; i < p->topo; i++) {
    printf("%d ", p->vetor[i]);
  }

  printf("]\n");
}

void empilharPilhaEstatica(PilhaEstatica *pilha, int x) {
  if(estaCheiaPilhaEstatica(pilha)) {
     printf("Warning: pilha cheia!\n");

     return;
  }

  pilha->vetor[pilha->topo] = x;
  pilha->topo++;
}


int topoPilhaEstatica(PilhaEstatica *pilha) {
  int ret = pilha->vetor[pilha->topo-1];
 
  return(ret);
}


int desempilharPilhaEstatica(PilhaEstatica *pilha) {
  if(estaVaziaPilhaEstatica(pilha)){
    printf("Warning: pilha está vazia!\n");
  } else {
    int ret = topoPilhaEstatica(pilha);
    
    pilha->topo--;
    
    return ret;
  }
}

void convertToBinary(int num, char* result) {
    char binario[32];

    // se o número for 0, não é necessário realizar toda a conversão
    if (num == 0) {
      strcpy(result, "0");
      
      return;
    }

    int i = 0;
    while (num > 0) {
      /*
        ex: num = 10. 
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
        Basicamente usamos esse código para fazer divisões sucessivas por 2 e achar o valor binário correspondente ao decimal.
      */
      binario[i++] = num % 2 == 1 ? '1' : '0';
      num = num / 2; 
    }

    // aqui é passado o resultado da conversao pro vetor que chega como parâmetro da função
    int j;
    for (j = 0; j < i; j++) {
      // o resultado é copiado de trás pra frente (i - j - 1)
      // já que o método de divisões sucessivas produz resultados invertidos
      result[j] = binario[i - j - 1];
    }

    result[j] = '\0';
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
      fprintf(arquivo_saida, "Arquivo inválido!\n");
      exit(11);
    }

    empilharPilhaEstatica(&pilha, numero);
  }

  fclose(arquivo_entrada);

  int tamPilha = tamanhoPilhaEstatica(&pilha);

  // se a pilha estiver vazia no final da operação, o arquivo estava vazio. Esse é o tratamento 
  if (tamPilha == 0) {
    fprintf(arquivo_saida, "Arquivo inválido!\n");
    exit(10);
  }

  for (int i = 0; i < tamPilha; i++) {
    int num = desempilharPilhaEstatica(&pilha);

    char binaryResult[32];
    convertToBinary(num, binaryResult);
  
    fprintf(arquivo_saida, "%s\n", binaryResult);
  }

  fclose(arquivo_saida);
  
  return 0;
}
