#include <stdio.h>

//Função que verifica se é esparsa
int eEsparsa(int ar[], int tam) {
  int zeros = 0;
  float pct;

  for(int i  = 0; i < tam; i++) {
    if (ar[i] == 0) {
      zeros++;
    }
  }

  pct = zeros*100/tam;

  if (pct > 70) {
    return 1;
  }
  else {
    return 0;
  }

}

int main() {
  int linha, col, tot;

  //Quantidade de linhas em uma matriz
  scanf("%d", &linha);
  //Quantidade de colunas em uma matriz
  scanf("%d", &col);

  //Total de elementos na matriz
  tot = linha*col;

  //Não criarei em duas dimensões, pois a análise dos elementos é geral
  int matriz[tot];

  for (int i = 0; i < tot; i++) {
    scanf("%d", &matriz[i]);
  }

  if(eEsparsa(matriz, tot)) {
    printf("A matriz é esparsa\n");
  }else {
    printf("A matriz não é esparsa\n");
  }


  return 0;
}