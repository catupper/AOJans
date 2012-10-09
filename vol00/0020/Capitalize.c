#include<stdio.h>
int main(){
  char x;
  while((x = getchar()) != EOF){
    if(x < 'a' || x > 'z')putchar(x);
    else putchar(x - 'a' + 'A');
  }
  return 0;
}
