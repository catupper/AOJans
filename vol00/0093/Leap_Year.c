#include<stdio.h>

int leap(int x){
  if(x % 400 == 0)return 1;
  if(x % 100 == 0)return 0;
  if(x % 4 == 0)return 1;
  return 0;
}

int main(){
  int a, b, num, i, first = 1;
  while(1){
    scanf("%d%d", &a, &b);
    if(a == 0 && b == 0)return 0;
    if(!first)puts("");
    first = 0;
    num = 0;
    for(i = a;i <= b;i++){
      if(leap(i)){
	printf("%d\n", i);
	num++;
      }
    }
    if(num == 0)puts("NA");
  }
}
