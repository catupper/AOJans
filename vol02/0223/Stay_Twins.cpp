#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 4000
typedef pair<int,int> p;
int xs[] = {0, 1, 0, -1}, ys[] = {1, 0, -1, 0};
int x, y;
int field[55][55];
bool dp[55][55][55][55];

int main(){
  int tx, ty, kx, ky;
  while(true){
    scanf("%d%d", &x, &y);
    memset(dp, false, sizeof(dp));
    memset(field, -1, sizeof(field));
    if(x == 0 && y == 0) return 0;
    scanf("%d%d", &tx, &ty);
    scanf("%d%d", &kx, &ky);
    for(int i = 1;i <= y;i++){
      for(int j = 1;j <= x;j++){
	scanf("%d", &field[j][i]);
      }
    }
    int ans = 0;
    bool fin = false;
    queue<pair<p, p> > q;
    q.push(make_pair(p(tx, ty), p(kx, ky)));
    dp[tx][ty][kx][ky] = true;
    while(!q.empty() && !fin && ans < 105){
      int len = q.size();
      ans++;
      while(len-- && !fin){
	pair<p, p> tmp;
	tmp = q.front();
	q.pop();
	for(int i = 0;i < 4;i++){
	  tx = tmp.first.first + xs[i];
	  ty = tmp.first.second + ys[i];
	  kx = tmp.second.first - xs[i];
	  ky = tmp.second.second - ys[i];
	  if(field[tx][ty] != 0){
	    tx = tmp.first.first;
	    ty = tmp.first.second;
	  }
	  if(field[kx][ky] != 0){
	    kx = tmp.second.first;
	    ky = tmp.second.second;
	  }
	  if(dp[tx][ty][kx][ky])continue;
	  dp[tx][ty][kx][ky] = true;
	  q.push(make_pair(p(tx, ty), p(kx, ky)));
	  if(tx == kx && ty == ky){
	    fin = true;
	    break;
	  }
	}
      }
    }
    if(!fin || ans >= 100)
      puts("NA");
    else
      printf("%d\n", ans);
  }
}
