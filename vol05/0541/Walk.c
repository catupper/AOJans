#include<stdio.h>
#include<string.h>

int main(){
  while(1){
    int h, w, n;
    int i, j;
    int field[1001][1001], dp[1001][1001];
    memset(field, -1, sizeof(field));
    memset(dp, 0, sizeof(dp));
    scanf("%d%d%d", &h, &w, &n);
    if(h == 0 && w == 0 && n == 0)return 0;
    for(i = 0;i < h;i++){
      for(j = 0;j < w;j++){
	scanf("%d", &field[i][j]);
      }
    }
    dp[0][0] = n;
    for(i = 0;i < h;i++){
      for(j = 0;j < w;j++){
	if(field[i][j] == 0){
	  dp[i][j + 1] += dp[i][j] / 2;
	  dp[i + 1][j] += dp[i][j] - dp[i][j] / 2;
	}
	else{
	  dp[i + 1][j] += dp[i][j] / 2;
	  dp[i][j + 1] += dp[i][j] - dp[i][j] / 2;
	}
	field[i][j] += dp[i][j];
	field[i][j] %= 2;
      }
    }
    int pi = 0, pj = 0;
    while(field[pi][pj] != -1){
      if(field[pi][pj] == 1){
	pi++;
      }
      else pj++;
    }
    printf("%d %d\n", pi + 1, pj + 1);
  }
}
