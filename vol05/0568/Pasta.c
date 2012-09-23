#include<stdio.h>

int pasta[100], dp[101][4][4];

int main(){
  int n, i ,j ,k, l;
  scanf("%d%d", &n, &k);
  for(i = 0;i < k;i++){
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    pasta[ai] = bi;
  }
  dp[0][0][0] = 1;
  for(i = 1;i <= n;i++){
    if(pasta[i] == 0){
      for(j = 1;j <= 3;j++){
	for(k = 0;k <= 3;k++){
	  for(l = 0;l <= 3;l++){
	    if(j == k && l == k)continue;
	    dp[i][j][k] += dp[i - 1][k][l];
	    dp[i][j][k] %= 10000;
	  }
	}
      } 
    }
    else{
      for(k = 0;k <= 3;k++){
	for(l = 0;l <= 3;l++){
	  if(pasta[i] == k && l == k)continue;
	  dp[i][pasta[i]][k] += dp[i - 1][k][l];
	  dp[i][pasta[i]][k] %= 10000;
	}
      }
    }
  }
  int ans = 0;
  for(i = 1;i <= 3;i++){
    for(j = 1;j <= 3;j++){
      ans += dp[n][i][j];
      ans %= 10000;
    }
  }
  printf("%d\n", ans);
  return 0;
}
