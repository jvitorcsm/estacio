// do-while always go exec and later verify validation

#include <stdio.h>

int main() {
  int i = 1;
  
  do {
    printf("Don't shout, the grandma is sleeping!\n");
    i++;
  } while (i <= 2);
  
};
