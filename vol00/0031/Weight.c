#include<stdio.h>

int main(){
  int d, first;
  while(scanf("%d", &d) != EOF){
    first = 1;
    while(d){
      if(!first)putchar(' ');
      first = 0;
      printf("%d", d & -d);
      d -= d & -d;
    }
    puts("");
  }
  return 0;
}
