#include <stdio.h>
#include <string.h>

typedef struct{
  char descricao[50];
  float peso;
  char tipo;
} Movel;

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
  int qtd, acimaDeDez = 0, terminaReal = 0, psdI = 0;

  scanf("%d%*c", &qtd);

  Movel moveis[qtd];

  for(int i = 0; i < qtd; i++) {
    //Descrição
    fgets(moveis[i].descricao, 50, stdin);
    removeEnter(moveis[i].descricao);
    //Peso e tipo
    scanf("%f%*c%c%*c", &moveis[i].peso, &moveis[i].tipo);
  }

  for (int i = 0; i < qtd; i++) {
    if(moveis[i].peso > 10 && moveis[i].tipo == 's') {
      acimaDeDez++;
    }

    if(strstr(moveis[i].descricao, "Real")) {
      terminaReal++;
    }

    if(moveis[i].peso > moveis[psdI].peso) {
      psdI = i;
    }

  }

  //Acima de dez
  printf("Tipo 's' acima de 10kg:%d\n",acimaDeDez);
  //Tem Real na descrição
  printf("Termina em \"Real\":%d\n", terminaReal);
  //Mais pesado descrição
  printf("Mais pesado: \"%s\"\n", moveis[psdI].descricao);

  return 0;
}