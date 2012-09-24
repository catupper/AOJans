#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
  while(true){
    int n, k, nums[100000], dp[100000][2], ans = 1, white = 0;
    scanf("%d%d", &n, &k);
    ans = 1;
    if(n == 0 && k == 0)return 0;
    for(int i = 0;i < k;i++){
      scanf("%d", nums + i);
      if(nums[i] == 0){
	white = 1;
	i--;
	k--;
      }
    }
    sort(nums, nums + k);
    dp[0][0] = 1;
    dp[0][1] = 2;
    for(int i = 1;i < k;i++){
      dp[i][0] = 1;
      dp[i][1] = 2;
      if(nums[i] - 1 == nums[i - 1]){
	dp[i][0] = dp[i - 1][0] + 1;
	dp[i][1] = dp[i - 1][1] + 1;
      }
      if(nums[i] - 2 == nums[i - 1]){
	dp[i][1] = dp[i - 1][0] + 2;
      }
      ans = max(ans, dp[i][0]);
      if(white == 1)ans = max(ans, dp[i][1]);
    }
    printf("%d\n", ans);
  }
}
