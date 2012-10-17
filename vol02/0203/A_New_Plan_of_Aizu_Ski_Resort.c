#include<stdio.h>
#include<string.h>
int main(){
  while(1){
    int dp[17][17], cond[17][17], x, y, i, j;
    int ans = 0;
    scanf("%d%d", &x, &y);
    if(x == 0 && y == 0)return 0;
    memset(dp, 0, sizeof(dp));
    for(i = 0;i < y;i++){
      for(j = 1;j <= x;j++){
	scanf("%d", &cond[i][j]);
      }
    }
    for(i = 0;i < y;i++){
      for(j = 1;j <= x;j++){
	if(i == 0)
	  dp[i][j] = !cond[i][j];
	if(cond[i][j] == 2)
	  dp[i + 2][j] += dp[i][j];
	if(cond[i][j] == 0){
	  if(cond[i + 1][j] != 1)
	    dp[i + 1][j] += dp[i][j];
	  if(cond[i + 1][j - 1] == 0)
	    dp[i + 1][j - 1] += dp[i][j];
	  if(cond[i + 1][j + 1] == 0)
	    dp[i + 1][j + 1] += dp[i][j];
	}	
      }
    }
    for(j = 1;j <= x;j++){
      if(cond[y - 1][j] != 1)
	ans += dp[y - 1][j];
      if(cond[y - 2][j] == 2)
	ans += dp[y - 2][j];
    }
    printf("%d\n", ans);
  }
}
