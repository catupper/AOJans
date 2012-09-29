#include<cstdio>
#include<cstring>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
#define INF (1<<30)

int dp[11][2012], ans;
vector<int> books[11];

int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++){
    int c, g;
    scanf("%d%d", &c, &g);
    books[g].push_back(c);
  }
  for(int i = 1;i <= 10;i++){
    sort(books[i].begin(), books[i].end(), greater<int>());
    for(int j = 1;j < books[i].size();j++){
      books[i][j] += books[i][j - 1];
    }
    for(int j = 0;j < books[i].size();j++){
      books[i][j] += j * (j + 1);
    }
  }
  for(int i = 0;i <= 10;i++){
    for(int j = 0;j < 2012;j++){
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for(int i = 1;i <= 10;i++){
    dp[i][0] = 0;
    for(int j = 1;j <= k ;j++){
      dp[i][j] = dp[i - 1][j];
      for(int l = 1;l <= j && l <= books[i].size();l++){
	dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + books[i][l - 1]);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}
