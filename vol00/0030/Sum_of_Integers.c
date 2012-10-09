#include<stdio.h>

int dp[10][10][100];

int main(){
  int i, j, k, n, s;
  dp[0][0][0] = dp[0][1][0] = 1;
  for(i = 1;i < 10;i++){
    for(j = 0;j < 10;j++){
      for(k = 0;k < 100;k++){
	dp[i][j][k] = dp[i - 1][j][k];
	if(k - i >= 0 && j > 0){
	  dp[i][j][k] += dp[i - 1][j - 1][k - i];
	}
      }
    }
  }
  while(1){
    scanf("%d%d", &n, &s);
    if(n == 0 && s == 0)return 0;
    if(s >= 100)puts("0");
    else printf("%d\n", dp[9][n][s]);
  }
}
