#include <stdio.h>

typedef struct {
  char nome[50];
  int numero, votos;
} candidato;

//Função que remove o \n de strings
void removeEnter(char string[]) { 
  for(int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
  }
}

int main() {
  int qtd, iMaior = 0;
  float totais = 0, nulos = 0;

  //Quantidade de candidatos
  scanf("%d", &qtd);

  //Lista de candidatos
  candidato lista[qtd];

  for (int i = 0; i < qtd; i++) {
    //Número do candidato
    scanf("%d%*c", &lista[i].numero);
    //Nome do candidato
    fgets(lista[i].nome, 50, stdin);
    lista[i].votos = 0;
    //Remover \n do nome
    removeEnter(lista[i].nome);
  }

  while(1) {
    int numero_entrada;

    //Número que o eleitor irá escolher
    scanf("%d", &numero_entrada);

    //Número menor ou igual a zero, a eleição se encerra
    if (numero_entrada <= 0)
      break;

    //Verificando de qual candidato é o número
    for (int i = 0; i < qtd; i++) {
      if (numero_entrada == lista[i].numero) {
        lista[i].votos++;
        break;
      }
    }

    totais++;
  }

  nulos = totais;

  //Verificando vencendor
  for (int i = 0; i < qtd; i++) {
    if (lista[i].votos > lista[iMaior].votos) {
      iMaior = i;
    }
  }

  for (int i = 0; i < qtd; i++) {
    nulos -= lista[i].votos;
    printf("%.2f - %d - %s ", lista[i].votos*100/totais, lista[i].numero, lista[i].nome);
    if (i == iMaior)
      printf("VENCEDOR\n");
    else
      printf("\n");
  }

  printf("%.2f - Nulos\n", nulos*100/totais);

  return 0;
}