#include<stdio.h>

int main(){
  double x;
  while(scanf("%lf", &x) != EOF){
    printf("%d\n", (int)(((x / 9.8) * (x / 9.8) * 4.9 + 5) / 5) + 1);
  }
  return 0;
}
