#include<cstdio>
#include<cstring>
int n, m, field[11][11], si, sj, num;

int dfs(int x, int y){
  int ans = 0;
  if(num == 0){
    if(x == si || y == sj)return 1;
    else return 0;
  }
  field[x][y] = 0;
  for(int i = x + 1;i < m;i++){
    if(field[i][y] == 1){
      num--;
      ans += dfs(i, y);
      num++;
      break;
    }
  } 
  for(int i = x - 1;i >= 0;i--){
    if(field[i][y] == 1){
      num--;
      ans += dfs(i, y);
      num++;
      break;
    }
  } 
  for(int i = y + 1;i < n;i++){
    if(field[x][i] == 1){
      num--;
      ans += dfs(x, i);
      num++;
      break;
    }
  } 
  for(int i = y - 1;i >= 0;i--){
    if(field[x][i] == 1){
      num--;
      ans += dfs(x, i);
      num++;
      break;
    }
  }  
  field[x][y] = 1;
  return ans;
}

int main(){
  while(1){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    memset(field, 0, sizeof(field));
    num = 0;
    for(int i = 0;i < m;i++){
      for(int j = 0;j < n;j++){
	scanf("%d", &field[i][j]);
	if(field[i][j] == 2){
	  si = i;
	  sj = j;
	}
	else num += field[i][j];
      }
    }
    printf("%d\n", dfs(si, sj));
  }
}
