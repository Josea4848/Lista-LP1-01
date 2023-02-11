#include <stdio.h>

//Definição do tipo estruturado para jogador
typedef struct {
  char nome[50];
  int idade;
  float chutes, gols;
} jogador;

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
  jogador j1, j2;
  float pont1, pont2;

  //Jogador 1
  fgets(j1.nome, 50, stdin);
  //Idade, chutes e gols
  scanf("%d%f%f%*c", &j1.idade, &j1.chutes, &j1.gols);

  //Jogador 2
  fgets(j2.nome, 50, stdin);
  //Idade, chutes e gols
  scanf("%d%f%f", &j2.idade, &j2.chutes, &j2.gols);

  //Pontaria do jogador 1
  pont1 = j1.gols/j1.chutes;
  //Pontaria do jogador 2
  pont2 = j2.gols/j2.chutes;
  
  printf("%f %f", pont1, pont2);

  removeEnter(j1.nome);
  removeEnter(j2.nome);

  if (pont1 > pont2) {
    printf("%s (%d)\n", j1.nome, j1.idade);
  }else {
    printf("%s (%d)\n", j2.nome, j2.idade);
  }

  return 0;
}