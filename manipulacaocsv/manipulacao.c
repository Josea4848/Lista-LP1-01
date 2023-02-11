#include <stdio.h>
#include <stdlib.h>

//Estrutura de pessoa
typedef struct {
  char nome[20], sobrenome[20], endereco[50], telefone[10];
  int cpf;
} pessoa;

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
  FILE *arq;
  int n;
  char linha[60];

  scanf("%d", &n);

  pessoa lista[n];

  for (int i = 0; i < n; i++) {
    //CPF
    scanf("%d%*c", &lista[i].cpf);
    //Nome
    fgets(lista[i].nome, 20, stdin);
    //Sobrenome
    fgets(lista[i].sobrenome, 20, stdin);
    //Endereço
    fgets(lista[i].endereco, 50, stdin);
    //Telefone
    fgets(lista[i].telefone, 10, stdin);
    //Removendo \n das strings
    removeEnter(lista[i].nome);
    removeEnter(lista[i].sobrenome);
    removeEnter(lista[i].endereco);
  }

  //Abrindo arquivo CSV
  arq = fopen("data.csv", "w+");

  //Se houver algum erro ao abrir arquivo
  if (!arq){
    printf("Erro ao abrir o arquivo!\n");
    return -1;
  }

  //Header 
  fprintf(arq, "CPF,nome,snome,endereço,telefone\n");

  //Escrevendo Linhas de informações para cada pessoa
  for (int i = 0; i < n; i++) {
    fprintf(arq, "%d,%s,%s,%s,%s", lista[i].cpf, lista[i].nome, lista[i].sobrenome, lista[i].endereco, lista[i].telefone);
  }

  //Retornando cursor para o início do arquivo
  rewind(arq);

  //Lendo arquivo CSV
  while(fgets(linha, 60, arq) != NULL) { 
    printf("%s", linha);
  }
  

  //Fechando arquivo  
  fclose(arq);

  return 0 ;
}