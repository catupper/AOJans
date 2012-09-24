#include<stdio.h>

int main(){
  int a = 0, b = 0, i, x;
  for(i = 0;i < 4;i++){
    scanf("%d", &x);
    a+=x;
  }
  for(i = 0;i < 4;i++){
    scanf("%d", &x);
    b+=x;
  }
  if(a > b)printf("%d\n", a);
  else printf("%d\n", b);
  return 0;
}
