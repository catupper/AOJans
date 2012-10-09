#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793238

int main(){
  double x = 0, y = 0, nowdig = 90;
  int a, b;
  while(1){
    scanf("%d,%d", &a, &b);
    if(a == 0 && b == 0)break;
    x += (double)a * cos(nowdig * PI / 180); 
    y += (double)a * sin(nowdig * PI / 180);
    nowdig -=  b;
  }
  printf("%d\n%d\n", (int)x, (int)y);
  return 0;
}
