#include<stdio.h>
#include<string.h>
int main(){
  while(1){
    int a, b, n, dp[20][20], i, j;
    scanf("%d%d%d", &a, &b, &n);
    if(a == 0 && b == 0) return 0;
    memset(dp, 0, sizeof(dp));
    for(i = 0;i < n;i++){
      int x, y;
      scanf("%d%d", &x, &y);
      dp[x][y] = -1;
    }
    dp[1][1] = 1;
    for(i = 1;i <= a;i++){
      for(j = 1;j <= b;j++){
	if(dp[i][j] == -1)dp[i][j] = 0;
	else dp[i][j]+= dp[i - 1][j] + dp[i][j - 1];
      }
    }
    printf("%d\n", dp[a][b]);
  }
}
