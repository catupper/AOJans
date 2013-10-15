#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
#define INF (1LL << 61)

long long froms[105000], fromg[105000], fs, fg;
map<int, long long> edge[105000];
vector<int> bit[105000];
int n, m, a, b, c, q;

void dijkstra(long long *dist, int start){
  dist[start] = 0;
  priority_queue<pair<long long , int>, vector<pair<long long , int> >, greater<pair<long long , int> > > pque;
  pque.push(make_pair(0, start));
  while(!pque.empty()){
    pair<long long , int> tmp = pque.top(); pque.pop();
    if(dist[tmp.second] < tmp.first)continue;
    map<int, long long >::iterator it = edge[tmp.second].begin();
    while(it != edge[tmp.second].end()){
      if( (*it).second + dist[tmp.second] < dist[(*it).first]){
	dist[(*it).first] = (*it).second + dist[tmp.second];
	pque.push(make_pair(dist[(*it).first], (*it).first));
      } 
      it++;
    }
  }
}

bool compgole(const int &a, const int &b){
  return fromg[a] > fromg[b];
};

bool compstart(const int &a, const int &b){
  return froms[a] < froms[b];
};

void add(int x, int y){
  while(x <= 102000){
    bit[x].push_back(y);
    x += x & -x;
  }
}

int solve(int x){
  int res = 0;
  while(x){
    res += upper_bound(bit[x].begin(), bit[x].end(), 103000, compstart) - bit[x].begin();
    x -= x & -x;
  }
  return res;
}

int main(){
  cin >> n >> m;
  fill(froms, froms + 105000, INF);
  fill(fromg, fromg + 105000, INF);
  for(int i = 0;i < m;i++){
    cin >> a >> b >> c;
    edge[a][b] = edge[b][a] = c;
  }
  dijkstra(froms, 0);
  dijkstra(fromg, n - 1);
  vector<int> chambers;
  for(int i = 0;i < n;i++){
    chambers.push_back(i);
  }
  sort(chambers.begin(), chambers.end(), compgole);
  for(int i = 0;i < n;i++){
    add(i + 1, chambers[i]);
  }
  for(int i = 1;i <= n;i++){
    sort(bit[i].begin(), bit[i].end(), compstart);
  }
  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> froms[103000] >> fromg[103000];
    int p = upper_bound(chambers.begin(), chambers.end(), 103000, compgole) - chambers.begin() - 1;
    cout << solve(p) << endl;
  }
  return 0;
}
