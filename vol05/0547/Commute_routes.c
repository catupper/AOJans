#include<stdio.h>
#define MOD 100000
struct DP{
  int up, right, tup, tright, way;
} dp[100][100];

int main(){
  int i, j = 0;
  for(i = 0;i <= 101;i++){
    for(j = 0;j <= 101;j++){
      if(i == 0 || j == 0){
	dp[i][j].up = 0;
	dp[i][j].right = 0;
	dp[i][j].tup = 0;
	dp[i][j].tright = 0;
	dp[i][j].way = 0;
      }
      else if(i == 1 && j == 1){
	dp[i][j].up = 1;
	dp[i][j].right = 1;
	dp[i][j].tup = 0;
	dp[i][j].tright = 0;
	dp[i][j].way = 1;
      }
      else{
	dp[i][j].right = (dp[i - 1][j].tright + dp[i - 1][j].right) % MOD;
	dp[i][j].up = (dp[i][j - 1].tup + dp[i][j - 1].up) % MOD;
	dp[i][j].tright = (dp[i][j - 1].up) % MOD;
	dp[i][j].tup = (dp[i - 1][j].right) % MOD;
	dp[i][j].way = (dp[i][j].right + dp[i][j].up) % MOD;
      }
    }
  }
  while(1){
    scanf("%d%d",&i,&j);
    if(i == 0 && j == 0)return 0;
    printf("%d\n", dp[i][j].way);
  }
}
