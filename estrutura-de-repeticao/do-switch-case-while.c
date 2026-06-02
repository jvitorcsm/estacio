#include <stdio.h>

int main() {
  
  int option;

  do {
    printf("\n");
    printf("What do you prefer?\n"
    "0. Nothing, Books, coffee, electronic music, and code make me happy.\n"
    "1. Go to the beach;\n"
    "2. Go traveling;\n"
    "3. Stay in home and study;\n"
    "4. Watch series a with warm blanket\n"
    "(10) - Exit). For stop program.\n");
    
    printf(">> ");
    if (scanf("%d", &option) != 1) {
      printf("\n");
      printf("Please enter valid number!\n");
      while (getchar() != '\n'); // Toda vez que digito algo que nao seja numero, o buffer valida condicao com \n, aye que isso seja verdadeiro (false), e o loop para.
      continue;
    };
   
    switch (option) {
      case 0:
        printf("--- Ihaaaa, I need more info!\n");
        break;
        case 1:
        printf("--- Let's go to the beach with our friends!\n");
        break;
      case 2:
        printf("--- Where I will go! The Russian cauntry wait me :P\n");
        break;
      case 3:
        printf("--- I will become the best Software Engineer!\n");
        break;
      case 4:
        printf("--- Well, We will watching Animal Planet, honey!\n");
        break;
      case 10:
        printf("--- Bye-bye!\n");
        break;
      default:
        printf(">> Invalid option, try again!\n");
    }
  } while (option != 10);
      return 0;
};
