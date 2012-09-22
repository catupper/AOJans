#include<stdio.h>
long long int dp[100][21];
int main(){
  int n, i, j, first, num, ans;
  scanf("%d", &n);
  scanf("%d", &first);
  dp[0][first] = 1;
  for(i = 1;i < n - 1;i++){
    scanf("%d", &num);
    for(j = 0;j <= 20;j++){
      if(j + num <= 20){
	dp[i][j] += dp[i - 1][j + num];
      }
      if(j - num >= 0){
	dp[i][j] += dp[i - 1][j - num];
      }
    }
  }
  scanf("%d", &ans);
  printf("%lld\n", dp[n - 2][ans]);
  return 0;
}
