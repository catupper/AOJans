#include<cstdio>
#include<cstring>
#include<set>
#include<map>
using namespace std;
int w, h, n;
int field[4000][4000];
pair<int, int> tapes[1000][2];
set<int> width, height;
map<int, int> widmap, heimap;

void dfs(int x, int y){
  if(x < 0 || y < 0 || x >= widmap[w] || y >= heimap[h] || field[x][y] != 0)return;
  field[x][y] = 1;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);     
}

int main(){
  while(1){
    memset(field, 0,sizeof(field));    
    scanf("%d%d", &w, &h);
    if(w == 0 && h == 0)return 0;
    width.clear();
    height.clear();
    widmap.clear();
    heimap.clear();
    width.insert(w);
    height.insert(h);
    
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      tapes[i][0] = make_pair(x1, y1);
      tapes[i][1] = make_pair(x2, y2);
      width.insert(x1);
      width.insert(x2);
      height.insert(y1);
      height.insert(y2);
    }
    set<int>::iterator it;
    int pos = !!(*width.begin());
    for(it = width.begin();it != width.end();it++, pos++){
      widmap[*it] = pos;
    }
    pos = !!(*height.begin());
    for(it = height.begin();it != height.end();it++, pos++){
      heimap[*it] = pos;
    }
    for(int i = 0;i < n;i++){
      int x1, x2, y1, y2;
      x1 = widmap[tapes[i][0].first];
      x2 = widmap[tapes[i][1].first];
      y1 = heimap[tapes[i][0].second];
      y2 = heimap[tapes[i][1].second];
      field[x1][y1]++;
      field[x2][y2]++;
      field[x1][y2]--;
      field[x2][y1]--;
    }
    for(int i = 0;i <= widmap[w];i++){
      for(int j = 1;j <= heimap[h];j++){
	field[i][j] += field[i][j - 1];
      }
    }
    for(int j = 0;j <= heimap[h];j++){
      for(int i = 1;i <= widmap[w];i++){
	field[i][j] += field[i - 1][j];
      }
    }
    int res = 0;
    for(int i = 0;i < widmap[w];i++){
      for(int j = 0;j < heimap[h];j++){
	if(field[i][j] == 0){
	  dfs(i, j);
	  res++;
	}
      }
    }
    printf("%d\n", res);
  }
}
