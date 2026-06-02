//We can use While for loop, he start with one condition become true and finish when this condiditon become false 

#include <stdio.h> // here I import library

int main() { // main function
  int i = 1; // declaration var
  while(i <= 10) { // condiditon (true), when "i" <= 10, he going sum more 1++, so 1,2,3,4,5,6...10,11. Because 11 is greater than 10 and not equal 10, this is my false condition. 
  printf("%.2d - John Little\n", i); // I just print in the screen caunt un 2 numbers 01, 02, 03 ..., and repeat my loop John Little.
  i++; // here I just say for C, hey guy, just sum more 1 after exec printf in var int i.
  };
};
