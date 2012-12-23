#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#define gs(x, r) (r==0?0:x[r-1])
using namespace std;
#define INF (1 << 29)
typedef pair<int, int> P; 
typedef pair<int, P> F;
int xs[] = {-1, 0, 1, 0}, ys[] = {0, 1, 0, -1};

vector<int> input_djk(int z){
  int w, h, x ,y;
  scanf("%d%d%d%d", &w, &h ,&x ,&y);
  int dist[w][h], level[w][h];
  bool used[w][h];
  priority_queue<F, vector<F>, greater<F> > pq;
  x--,y--;
  for(int j = 0;j < h;j++){
    for(int i = 0;i < w;i++){
      scanf("%d", &level[i][j]);
      dist[i][j] = INF;
      used[i][j] = false;
    }
  }
  dist[x][y] = 1;
  used[x][y] = true;
  pq.push(F(1, P(x, y)));
  while(!pq.empty()){
    F tmp = pq.top();pq.pop();
    int tx = tmp.second.first, ty = tmp.second.second;
    if(dist[tx][ty] < tmp.first)continue;
    for(int i = 0;i < 4;i++){
      if(tx + xs[i] < 0 || tx + xs[i] >= w || ty + ys[i] < 0 || ty + ys[i] >= h || used[tx + xs[i]][ty + ys[i]])continue;
      tx += xs[i], ty += ys[i];
      if(dist[tx][ty] > max(tmp.first, level[tx][ty])){
	dist[tx][ty] = max(tmp.first, level[tx][ty]);
	used[tx][ty] = true;
	pq.push(F(dist[tx][ty], P(tx, ty)));
      }
      tx -= xs[i], ty -= ys[i];
    }
  }
  vector<int> res;
  for(int i = 0;i < w;i++)
    for(int j = 0;j < h;j++)
      res.push_back(dist[i][j]);
   
  sort(res.begin(), res.end());
  return res;
}


int solve(vector<int> a, vector<int> b, int r){
  int res = INF;
  for(int i = min(r,(int) a.size());i >= 0 && b.size() >= r - i;i--){
    res = min(res, gs(a, i) + gs(b, r - i));
  }
  return res;
}

int main(){
  while(true){
    int r;
    scanf("%d", &r);
    if(r == 0)return 0;
    vector<int> a, b;
    a = input_djk(0);
    b = input_djk(1);
    cout << solve(a, b, r) << endl;
  }
}
