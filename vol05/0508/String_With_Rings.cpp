#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> rings;
vector<int> neibs[101];
int used[101];

int dfs(int x){
  int res = 1;
  used[x] = 1;
  for(int i = 0;i < neibs[x].size();i++){
    if(used[neibs[x][i]] == 0){
      int tmp = dfs(neibs[x][i]);
      res = max(res, tmp + 1);
    }
  }
  used[x] = 0;
  return res;
}

int main(){
  while(1){
    int n, res = 0;
    rings.clear();
    for(int i = 0;i < 101;i++)neibs[i].clear();
    scanf("%d", &n);
    if(n == 0)return 0;
    for(int i = 0;i < n;i++){
      int a, b;
      scanf("%d%d", &a, &b);
      rings.push_back(a);
      rings.push_back(b);
      neibs[a].push_back(b);
      neibs[b].push_back(a);
    }
    for(int i = 0;i < rings.size();i++){
      int tmp = dfs(rings[i]);
      res = max(res, tmp);
    }
    printf("%d\n", res);
  }
}
