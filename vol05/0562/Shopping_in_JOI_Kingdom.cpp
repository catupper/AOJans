#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<functional>
#include<algorithm>
#define INF (1<<28)
using namespace std;

int pass[3001][3001], maxpass[3001][3001];
int saitan[3001], ans;
int n, m, k;
priority_queue<pair<int, int> , vector<pair<int, int> >,greater<pair<int, int> > > que;
vector<int> neib[3001];



int main(){
  scanf("%d%d%d", &n, &m, &k);
  fill(saitan, saitan + 3001, INF);
  for(int i = 0;i < m;i++){
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    neib[a].push_back(b);
    neib[b].push_back(a);
    pass[a][b] = pass[b][a] = l;
  }
  for(int i = 0;i < k;i++){
    int s;
    scanf("%d", &s);
    saitan[s] = 0;
    que.push(make_pair(0, s));
    saitan[s] = 0;
  }
  while(!que.empty()){
    pair<int, int> tmp = que.top(); que.pop();
    if(saitan[tmp.second] < tmp.first)continue;
    for(int i = 0;i < neib[tmp.second].size();i++){
      int from = tmp.second;
      int to = neib[from][i];
      if(saitan[to] > saitan[from] + pass[from][to]){
	saitan[to] = saitan[from] + pass[from][to];
	que.push(make_pair(saitan[to], to));
      }    
    }    
  }
  for(int i = 1;i <= n;i++){
    for(int j = 0;j < neib[i].size();j++){
      int to = neib[i][j];
      ans = max(ans, (1 + saitan[i] + saitan[to] + pass[i][to]) / 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
