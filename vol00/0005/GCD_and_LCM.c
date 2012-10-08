#include<stdio.h>

int gcd(int a, int b){
  if(a == 0)return b;
  else return gcd(b % a, a);
}

int lcm(int a, int b){
  return a / gcd(a, b) * b;
}

int main(){
  int x, y;
  while(scanf("%d%d", &x, &y) != EOF){
    printf("%d %d\n", gcd(x, y), lcm(x, y));
  }
  return 0;
}
