#include<stdio.h>

int main(){
  int sum, i, a;
  while(1){
    scanf("%d", &sum);
    if(sum == 0)return 0;
    for(i = 0;i < 9;i++){
      scanf("%d", &a);
      sum -= a;	
    }
    printf("%d\n", sum);
  }
}
