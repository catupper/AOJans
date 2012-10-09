#include<stdio.h>

int main(){
  int hisi = 0, quat = 0, a, b, c;
  while(scanf("%d,%d,%d", &a, &b, &c) != EOF){
    if(a * a + b * b == c * c)quat++;
    if(a == b)hisi++;
  }
  printf("%d\n%d\n", quat, hisi);
  return 0;
}
