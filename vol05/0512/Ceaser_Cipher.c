#include<stdio.h>

int main(){
  char c;
  while(1){
    c = getchar();
    if(c == '\n'){
      puts("");
      return 0;
    }
    int x = c - 'A';
    x = (x + 23) % 26;
    putchar('A' + x);
  }
}
