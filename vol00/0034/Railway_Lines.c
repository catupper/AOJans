#include<stdio.h>

int rail[10], a, b, i, sum, s;

int main(){
  while(1){
    sum = 0;
    for(i = 0;i < 10;i++){
      scanf("%d,", rail + i);
      sum += rail[i];
    }
    if(scanf("%d,%d", &a, &b) == EOF)return 0;
    s = 0;
    for(i = 0;i < 10;i++){
      s += rail[i];
      if(s * b >= (sum - s) * a){
	printf("%d\n", i + 1);
	break;
      }
    }
  }
}
