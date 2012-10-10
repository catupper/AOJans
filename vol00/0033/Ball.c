#include<stdio.h>
#include<string.h>

int main(){
  int n, balls[10], cup[10], last, i;
  scanf("%d", &n);
  while(n--){
    memset(cup, 0, sizeof(cup));
    last = 0;
    for(i = 0;i < 10;i++){
      scanf("%d", balls + i);
      if(balls[i] > last){
	cup[i] = 1;
	last = balls[i];
      }
    }
    last = 0;
    for(i = 0;i < 10;i++){
      if(cup[i] == 0){
	if(last < balls[i])
	  last = balls[i];
	else
	  last = 20;
      }
    }
    if(last == 20){
      puts("NO");
    }
    else
      puts("YES");
  }
  return 0;
}
