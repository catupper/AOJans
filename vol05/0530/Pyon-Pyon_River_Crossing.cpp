#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#define INF (1 << 30)
using namespace std;

int main(){
  int n, m, tmp;
  while(1){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    int dp[3][10][100];
    memset(dp, 0, sizeof(dp));
    vector< pair<int, int> >stones[n];
    for(int i = 0;i < n;i++){
      int k, l, m;
      scanf("%d", &k);
      for(int j = 0;j < k;j++){
	scanf("%d %d", &l, &m);
	stones[i].push_back(make_pair(l, m));
      }
    }
    for(int i = 0;i < n;i++){
      int ind = i%3, prev = (i - 1) % 3, prepre = (i - 2) % 3;

      for(int j = 0;j < stones[i].size();j++)
	for(int k = 0;k <= m;k++)
	  dp[ind][j][k] = INF;

      for(int j = 0;j < stones[i].size();j++){
	if(i == 0)dp[ind][j][m] = 0;
	else if(i == 1 && m - 1 >= 0)dp[ind][j][m - 1] = 0;
      }
      for(int j = 0;j < stones[i].size();j++){
	for(int k = 0;k <= m;k++){
	  for(int l = 0;i > 0 && l < stones[i - 1].size();l++){
	    dp[ind][j][k] = min(dp[ind][j][k],
				dp[prev][l][k] + abs(stones[i - 1][l].first - stones[i][j].first) * (stones[i - 1][l].second + stones[i][j].second));
	  }
	  for(int l = 0;i > 1 && k < m && l < stones[i - 2].size();l++){
	    dp[ind][j][k] = min(dp[ind][j][k],
				dp[prepre][l][k + 1] + abs(stones[i - 2][l].first - stones[i][j].first) * (stones[i - 2][l].second + stones[i][j].second));
	  }
	}
      }
    }
    int res = INF;
    for(int i = 0;i < stones[n - 1].size();i++){
      for(int j = 0;j <= m;j++){
	res = min(res, dp[(n - 1) % 3][i][j]);
      }
    }
    for(int i = 0;i < stones[n - 2].size();i++){
      for(int j = 1;j <= m;j++){
	res = min(res, dp[(n - 2) % 3][i][j]);
      }
    }
    printf("%d\n", res);
  }
}
