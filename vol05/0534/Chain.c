#include<stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

int main(){
  while(1){

    int n, balls[10007], i;
    scanf("%d", &n);
    if(n == 0)return 0;
    
    balls[0] = -1;
    balls[n + 1] = -2;
    for(i = 1;i <= n;i++){
      scanf("%d", balls + i);
    }
    int res = n;
    for(i = 1;i <= n;i++){
      int up, down, ans, old = balls[i];
      balls[i] = balls[i + 1];
      up = i + 1;
      down = i;
      ans = 0;
      while(balls[up] == balls[down]){
	int erased = 0, color = balls[up];
	while(balls[up] == color){
	  up++;
	  erased++;
	}
	while(balls[down] == color){
	  down--;
	  erased++;
	}
	if(erased >= 4){
	  ans += erased;
	}
	else break;
      }
      res = min(res, n - ans);
      
      balls[i] = balls[i - 1];
      up = i;
      down = i - 1;
      ans = 0;
      while(balls[up] == balls[down]){
	int erased = 0, color = balls[up];
	while(balls[up] == color){
	  up++;
	  erased++;
	}
	while(balls[down] == color){
	  down--;
	  erased++;
	}
	if(erased >= 4){
	  ans += erased;
	}
	else break;
      
      }
      res = min(res, n - ans);
      
      balls[i] = old;
    }
    printf("%d\n", res);
  }
}
