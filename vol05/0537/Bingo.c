#include<stdio.h>
#include<string.h>

int dp[100][3001];
int main(){
  while(1){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int n, m, s, i, j, k, ans = 0;
    scanf("%d%d%d", &n, &m, &s);
    if(n == 0 && m == 0 && s == 0)return 0;
    n *= n;
    for(i = 1;i <= m;i++){
      for(j = n;j > 0;j--){
	for(k = i;k <= s;k++){
	  dp[j][k] += dp[j - 1][k - i];
	  dp[j][k] %= 100000;
	}
      }
    }
    printf("%d\n", dp[n][s]);
  }
}
