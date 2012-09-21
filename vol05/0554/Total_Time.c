#include<stdio.h>

int main(){
  int x = 0, i, t;
  for(i = 0;i < 4;i++){
    scanf("%d", &t);
    x += t;
  }
  printf("%d\n%d\n", x / 60, x % 60);
  return 0;
}
