#include<stdio.h>
 
int field[105][105] ,n ,m;
 
int dfs(int x, int y){
  if(x < 0 || x > m + 2 || y < 0 || y > n + 2)return 0;
  if(field[x][y] == 1)return 1;
  if(field[x][y] == 2)return 0;
  int res = 0;
  field[x][y] = 2;
  res += dfs(x, y + 1);
  res += dfs(x, y - 1);
  res += dfs(x + 1, y);
  res += dfs(x - 1, y);
  if(x % 2 == 0){
    res += dfs(x - 1, y - 1);
    res += dfs(x + 1, y - 1);
  }
  else{
    res += dfs(x - 1, y + 1);
    res += dfs(x + 1, y + 1);
  }
  return res;
}
 
int main(){
  int i, j;
  scanf("%d%d", &n, &m);
  for(i = 1;i <= m;i++){
    for(j = 1;j <= n;j++){
      scanf("%d", &field[i][j]);
    }
  }
  printf("%d\n", dfs(0, 0));
  return 0;
}
