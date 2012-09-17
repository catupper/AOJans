#include<stdio.h>

int field[91][91], n, m;
int xm[] = {0, 1, 0, -1}, ym[] = {1, 0, -1, 0};
int dfs(int x, int y){
  int i, res = 1;
  for(i = 0;i < 4;i++){
    int nx = x + xm[i];
    int ny = y + ym[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
      continue;
    }
    field[x][y] = 0;
    if(field[nx][ny] == 1){
      int longest = dfs(nx, ny) + 1;
      if(longest > res){
	res = longest;
      }
    }
    field[x][y] = 1;
  }
  return res;
}

int main(){
  while(1){
    int i, j, max = 0;
    scanf("%d%d", &m, &n);
    if(m == 0 && n == 0){
      break;
    }

    for(i = 0;i < n;i++){
      for(j = 0;j < m;j++){
	scanf("%d",field[i] + j);
      }
    }
    
    for(i = 0;i < n;i++){
      for(j = 0;j < m;j++){
	if(field[i][j] == 1){
	  int longest = dfs(i, j);
	  if(longest > max){
	    max = longest;
	  }
	}
      }
    }
    printf("%d\n",max);
  }
  return 0;
}
