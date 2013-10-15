#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
#define INF (1LL << 61)

long long froms[105000], fromg[105000];
map<int, long long> edge[105000];

void dijkstra(long long *dist, int start){
  dist[start] = 0;
  priority_queue<pair<long long , int>, vector<pair<long long , int> >, greater<pair<long long , int> > > pque;
  pque.push(make_pair(0, start));
  while(!pque.empty()){
    pair<long long , int> tmp = pque.top(); pque.pop();
    if(dist[tmp.second] < tmp.first)continue;
    dist[tmp.second] = tmp.first;
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

struct rtn{
  vector<int> starts;
  int minimum, size;
  bool end;
  rtn *l, *r;
};

bool compgole(const int &a, const int &b){
  return fromg[a] < fromg[b];
};

bool compstart(const int &a, const int &b){
  return froms[a] < froms[b];
};

rtn* make_rtn(vector<int> chambers){
  rtn* res = new rtn;
  vector<int> tmp;
  int rp = 0, lp = 0;
  if(chambers.size() == 1){
    res -> starts = chambers;
    res -> minimum = chambers[0];
    res -> end = true;
    res -> size = 1;
  }
  else{
    res -> size = chambers.size();
    for(int i = 0;i < res -> size / 2;i++){
      res -> starts.push_back(chambers.back());
      chambers.pop_back();
    }
    for(int i = 0;i < res -> size / 2;i++){
      tmp.push_back(res -> starts.back());
      res -> starts.pop_back();
    }
    res -> l = make_rtn(chambers);
    res -> r = make_rtn(tmp);
    for(int i = 0;i < res -> size;i++){
      if(rp == res -> r -> starts.size()){
	res -> starts.push_back(res -> l -> starts[lp++]);
      }
      else if(lp == res -> l -> starts.size()){
	res -> starts.push_back(res -> r -> starts[rp++]);
      }
      else if(froms[res -> r -> starts[rp]] < froms[res -> l -> starts[lp]]){
	res -> starts.push_back(res -> r -> starts[rp++]);
      }
      else{
	res -> starts.push_back(res -> l -> starts[lp++]);
      }
    }
    res -> minimum = res -> l -> minimum;
    res -> end = false;
  }
  return res;
}

int solve(long long int goalbottom, long long int starttop, rtn* root){
  if(fromg[root -> minimum] >= goalbottom){
    froms[103000] = starttop;
    return upper_bound(root -> starts.begin(), root -> starts.end(), 103000, compstart) - root -> starts.begin(); 
  }
  else if(root -> end){
    return 0;
  }
  else if(fromg[root -> r -> minimum] >= goalbottom){
    return solve(goalbottom, starttop, root -> r) + solve(goalbottom, starttop, root -> l);
  }
  else{
    return solve(goalbottom, starttop, root -> r);
  }
}

int main(){
  int n, m, a, b, c, q;
  long long fs, fg;
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
  rtn* root = make_rtn(chambers);
  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> fs >> fg;
    cout << solve(fg, fs, root) << endl;
  }
  return 0;
}
/*

0 3 1

2   4

2 1 3
*/
