#include <stdio.h>

typedef struct {
  int dia, mes, ano;
}data;

//Função que avalia data mais antiga
int maisAntigo(data d1, data d2) {
  //Datas iguais
  if (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia) {
    return 0;
  }
  else if (d1.ano < d2.ano || (d1.ano == d2.ano && d1.mes < d2.mes) || (d1.ano==d2.ano && d1.mes == d2.mes & d1.dia < d2.dia)) {
    return 1;
  }
  return -1;
  
}

int main() {
  data d1, d2;
  int result;

  //Data 1
  scanf("%d%d%d", &d1.dia, &d1.mes, &d1.ano);

  //Data 2
  scanf("%d%d%d", &d2.dia, &d2.mes, &d2.ano);

  result = maisAntigo(d1, d2);

  if (!result)
    printf("Pessoas são da mesma idade\n");
  else if (result == 1)
    printf("Pessoa 1 é mais velha\n");
  else 
    printf("Pessoa 2 é mais velha\n");

}
