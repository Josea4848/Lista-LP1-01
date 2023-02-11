#include <stdio.h>

typedef struct {
  char marca[30], modelo[30];
  int ano, preco;
} carro;


int main() {  
  carro veiculo1, veiculo2;

  /*===== Veículo 1 =====*/
  //Modelo
  scanf("%s", veiculo1.modelo);
  //Marca
  scanf("%s", veiculo1.marca);
  //Ano
  scanf("%d%d%*c", &veiculo1.ano, &veiculo1.preco);
  //Veículo 1 END

  /*===== Veículo 2 =====*/
  //Modelo
  scanf("%s", veiculo2.modelo);
  //Marca
  scanf("%s", veiculo2.marca);
  //Ano
  scanf("%d%d", &veiculo2.ano, &veiculo2.preco);
  //Veículo 2 END

  if (veiculo1.ano == veiculo2.ano) {
    if (veiculo1.preco < veiculo2.preco)
      printf("%s %s\n", veiculo1.marca, veiculo1.modelo);
    else
      printf("%s %s\n", veiculo2.marca, veiculo2.modelo);
  }
  else if (veiculo1.ano < veiculo2.ano) {
    printf("%s %s\n", veiculo1.marca, veiculo1.modelo);
  }
  else {
    printf("%s %s\n", veiculo2.marca, veiculo2.modelo);
  }

  return 0;
}