#include<stdio.h>

int main(){
  int a, b;
  while(scanf("%d %d",&a,&b) != EOF){
    int sum = a + b,res = 0;
    while(sum > 0){
      res++;
      sum /= 10;
    }
    printf("%d\n",res);
  }
  return 0;
}
