#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1 << 30)
typedef pair<long long , long long > EDGE;
typedef pair<long long , EDGE> COST;

vector<EDGE> edge[100100], edges;
long long  dist[100100];
int  parents[100100][31];
long long  minimum[100100][31];
long long  depth[100100];
long long  u[100100];
long long  k, f, n, m, a, b, l, s, t, q;
void dijkstra(){//fill dist
  priority_queue<pair<long long, long long> ,vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
  for(long long  i = 0;i < k;i++){
    cin >> f;
    dist[f] = 0;
    pq.push(make_pair(0, f));
  }
  while(!pq.empty()){
    pair<long long , long long> tmp = pq.top();pq.pop();
    long long  node = tmp.second;
    if(dist[node] < tmp.first)continue;
    for(long long  i = 0;i < edge[node].size();i++){
      if(dist[edge[node][i].first] > edge[node][i].second + dist[node]){
	dist[edge[node][i].first] = edge[node][i].second + dist[node];
	pq.push(make_pair(dist[edge[node][i].first], edge[node][i].first));
      }
    }
  }
}



long long  unin(long long  x){
  if(u[x] == x)return x;
  return u[x] = unin(u[x]);
}

void unite(long long  a, long long  b){
  a = unin(a);
  b = unin(b);
  u[b] = a;
}

void ddfs(long long  x, long long  d, long long  last){
  depth[x] = d;
  parents[x][0] = last;
  if(last != -INF)  minimum[x][0] = min(dist[x], dist[last]);
  else minimum[x][0] = -INF;
  for(long long  i = 0;i < edge[x].size();i++){
    if(edge[x][i].first == last)continue;
    ddfs(edge[x][i].first, d + 1, x);
  }
}

void make_tree(){
  priority_queue<COST> pq;
  for(long long  i = 0;i <= n;i++)edge[i].clear();
  for(long long  i = 0;i < edges.size();i++){
    long long  a = edges[i].first, b = edges[i].second;
    pq.push(COST(min(dist[a], dist[b]), edges[i]));
  }
  for(long long  i = 1;i <= n;i++)u[i] = i;
  while(!pq.empty()){
    COST tmp = pq.top();pq.pop();
    long long  a = tmp.second.first, b = tmp.second.second;
    if(unin(a) == unin(b))continue;
    edge[a].push_back(EDGE(b, tmp.first));
    edge[b].push_back(EDGE(a, tmp.first));
    unite(a, b);
  }
  ddfs(1, 0, -INF);//fill depth and parents[i][0]
  for(long long  i = 1;i <= 30;i++){
    for(long long  j = 0;j <= n;j++){
      if(parents[j][i - 1] != -INF){
	parents[j][i] = parents[parents[j][i - 1]][i - 1];
	minimum[j][i] = min(minimum[j][i - 1], minimum[parents[j][i - 1]][i - 1]);
      }
      else{
	parents[j][i] = -INF;
	minimum[j][i] = -INF;
      }
    }
  }
}

long long  above(long long  x, long long  d, long long  r){
  if(x == -INF)return -INF;
  if(d == 0)return x;
  while((1 << r) > d)r--;
  return above(parents[x][r], d - (1 << r), r);
}

long long  mini(long long  x, long long  d, long long  r){
  if(d == 0)return dist[x];
  while((1 << r) > d)r--;
  return min(minimum[x][r], mini(parents[x][r], d - (1 << r), r));
}

long long  solve(long long  a, long long  b){
  long long  res;
  if(depth[a] < depth[b])swap(a, b);
  res = mini(a, depth[a] - depth[b], 30);
  a = above(a, depth[a] - depth[b], 30);
  if(a == b)return res;
  long long  top = 100100, bottom = 0;
  while(top - bottom > 1){
    long long  mid = (top + bottom) / 2;
    if(above(a, mid, 30) == above(b, mid, 30))
      top = mid;
    else
      bottom = mid;
  }

  res = min(res, mini(a, top, 30));
  res = min(res, mini(b, top, 30));
  return res;
}

int  main(){
  fill(dist, dist + 100100, INF);
  cin >> n >> m >> k >> q;
  for(long long  i = 0;i < m;i++){
    cin >> a >> b >> l;
    edge[a].push_back(EDGE(b,l));
    edge[b].push_back(EDGE(a,l));
    edges.push_back(EDGE(a,b));
  }
  dijkstra();
  make_tree();
  for(long long  i = 0;i < q;i++){
    cin >> s >> t;
    cout << solve(s, t) << endl;
  }
  return 0;
}

