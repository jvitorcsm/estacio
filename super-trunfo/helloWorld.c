#include <stdio.h>

int main() {
  
  int idade;
  float altura;
  double saldoBancario;
  char inicial = 'J';
  char name[5];

  printf("What's your name? \n>> ");
    scanf("%s", &name);
  printf("Wassup, %s!\n", name);

  putchar('\n');

  printf("What's your age? \n>> ");
    scanf("%i", &idade);
  printf("I'm %i years old\n", idade);

  putchar('\n');

  printf("What's your height? \n>> ");
    scanf("%f", &altura);
  printf("I'm %.2f metter tall\n", altura);

  putchar('\n');

  printf("What's your currente balance? \n>> ");
    scanf("%lf", &saldoBancario); // Usamos 'lf' para double no scanf
  printf("My current balance is: %.2f\n", saldoBancario);

  return 0;
}
