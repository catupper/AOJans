#include<stdio.h>

int main(){
  int submit[31], i, x;
  for(i = 0;i < 31;i++)submit[i] = 0;
  for(i = 0;i < 28;i++){
    scanf("%d", &x);
    submit[x] = 1;
  }
  for(i = 1;i < 31;i++){
    if(submit[i] == 0){
      printf("%d\n", i);
    }
  }
  return 0;
}
