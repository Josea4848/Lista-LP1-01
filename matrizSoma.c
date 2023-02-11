#include <stdio.h>

//Função que soma matrizes
void SomaMatriz(int matriz1[], int matriz2[], int l, int col) {
  int result[l][col], indice = 0, total = l*col;
  
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < col; j++) {
        result[i][j] = matriz1[indice] + matriz2[indice];
        indice++;
    }
  }

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d", result[i][j]);

      if (j != col - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

}

int main() {
  int linha, col, tot;

  //Input para número de linhas e colunas
  scanf("%d %d", &linha, &col);

  tot = linha*col;

  //Utilizarei arrays de uma dimensão
  int matriz1[tot], matriz2[tot];

  //Matriz 1
  for(int i =  0; i < tot; i++) {
    //elementos
    scanf("%d", &matriz1[i]);
  }

  //Matriz 2
  for(int i =  0; i < tot; i++) {
    //elementos
    scanf("%d", &matriz2[i]);
  }

  SomaMatriz(matriz1, matriz2, linha, col);

  return 0;
}