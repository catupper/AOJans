#include<stdio.h>

long long int  dp[2][10];
int  n, m, nums[10];
char id[100005];

int main(){
  dp[1][0] = 1;
  scanf("%d", &n);
  scanf("%s", id);
  scanf("%d", &m);
  for(int i = 0;i < m;i++){
    scanf("%d", nums + i);
  }
  for(int i = 0;i < n;i++){
    int twotime = 1;
    if((n - i) % 2 == 0){
      twotime = 2;
    }
    if(id[i] == '*'){
      for(int j = 0;j < 10;j++){
	dp[i % 2][j] = 0;
	for(int k = 0;k < m;k++){
	  int add = (nums[k] * twotime) % 10 + (nums[k] * twotime) / 10;
	  dp[i % 2][j] += dp[1 - (i % 2)][(j + 10 - add) % 10];
	}
      }
    }
    else{
      int k = id[i] - '0';
      for(int j = 0;j < 10;j++){
	dp[i % 2][j] = 0;
	int add = (k * twotime) % 10 + (k * twotime) / 10;
	dp[i % 2][j] += dp[1 - i % 2][(j + 10 - add) % 10];
      }
    }
  }
  printf("%lld\n", dp[(n - 1) % 2][0]);
}
