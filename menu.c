#include <stdio.h>

void ExibeMenu(){
  printf("1 - Item 1\n");
  printf("2 - Item 2\n");
  printf("3 - Item 3\n");
  printf("4 - Sair\n");
}

int main() {

  //Repetição do Menu até o número 4
  while (1) {
    int user_input;

    ExibeMenu();

    scanf("%d", &user_input);

    if (user_input == 4) {
      printf("Sair\n");
      break;
    }
    else if (user_input >= 1 && user_input <= 3) {
      printf("Item %d\n", user_input);
    }
    else {
      printf("Opcao %d Invalida\n", user_input);
    }
  }

  return 0;
}