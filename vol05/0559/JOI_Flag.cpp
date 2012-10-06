#include<cstdio>
#include<cstring>
int m, n, ans;
int dp[2][1 << 19][2], fill, all = 1;
char c;
int main(){
  scanf("%d%d", &m, &n);
  fill = (1 << (n - 1)) - 1;
  dp[1][0][0] = 1;
  for(int i = 0;i < m * n;i++){
    scanf(" %c", &c);
    if(c == '?'){
      all *= 3;
      all %= 100000;
    }
    memset(dp[i % 2], 0, sizeof(dp[i % 2]));
    for(int j = 0;j <= fill;j++){
      int next = (j << 1) & fill;
      if(c == 'J' || c == '?'){
	dp[i % 2][next][1] += dp[(i + 1) % 2][j][0] + dp[(i + 1) % 2][j][1];
      }
      if(c == 'O' || c == '?'){
	dp[i % 2][next][0] += dp[(i + 1) % 2][j][0];
	dp[i % 2][next + 1][0] += dp[(i + 1) % 2][j][1];
      }
      if(c == 'I' || c == '?'){
	if(j >> (n - 2) == 0 || i % n == n - 1){
	  dp[i % 2][next][0] += dp[(i + 1) % 2][j][0] + dp[(i + 1) % 2][j][1];
	}
      }
      dp[i % 2][next][0] %= 100000;
      dp[i % 2][next][1] %= 100000;
      dp[i % 2][next + 1][0] %= 100000;
      dp[i % 2][next + 1][1] %= 100000;
    }
  }
  for(int i = 0;i <= fill;i++){
    ans += dp[(m * n - 1) % 2][i][0] + dp[(m * n - 1) % 2][i][1];
    ans %= 100000;
  }
  printf("%d\n", (100000 + all - ans) % 100000);
  return 0;  
}
