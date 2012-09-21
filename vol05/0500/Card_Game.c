#include<stdio.h>

int main(){
  while(1){
    int n, a = 0, b = 0, x, y, i;
    scanf("%d", &n);
    if(n == 0)return 0;
    for(i = 0;i < n;i++){
      scanf("%d%d",&x ,&y);
      if(x == y){
	a += x;
	b += y;
      }
      else if(x > y){
	a += x + y;
      }
      else if(x < y){
	b += x + y;
      }
    }
    printf("%d %d\n", a, b);
  }
}
