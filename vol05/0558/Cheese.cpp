#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

int used[1000][1000];
int field[1000][1000];
int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
int main(){
  int h, w, n, sx, sy, ans = 0;
  scanf("%d%d%d", &h, &w, &n);
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      char c;
      scanf(" %c", &c);
      if(c =='.' || c == 'S')field[i][j] = 0;
      else if(c == 'X')field[i][j] = -1;
      else field[i][j] = c - '0';
      if(c == 'S')sx = i, sy = j;
    }
  }
  for(int goal = 1;goal <= n;goal++){
    memset(used, 0, sizeof(used));
    queue< pair<int, int> > qu;
    qu.push(make_pair(sx, sy));
    bool fin = false;
    while(!fin){
      ans++;
      for(int i = qu.size();i > 0 && !fin;i--){
	int tx = qu.front().first;
	int ty = qu.front().second;
	qu.pop();
	for(int j = 0;j < 4 && !fin;j++){
	  int nx = tx + mx[j];
	  int ny = ty + my[j];
	  if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
	  if(field[nx][ny] == -1 || used[nx][ny] != 0)continue;
	  used[nx][ny] = 1;
	  if(field[nx][ny] == goal){
	    fin = true;
	    sx = nx;
	    sy = ny;
	  }
	  qu.push(make_pair(nx, ny));
	}
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
