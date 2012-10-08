#include<stdio.h>

int main(){
  int a, b, c, d, e, f, x, y;
  while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) != EOF){
    x = (c * e - f * b) * 100000 / (a * e - d * b) + 5;
    y = (c * d - f * a) * 100000 / (b * d - e * a) + 5;
    printf("%.3lf %.3lf\n", x * 0.00001, y * 0.00001);
  }
  return 0;
}
