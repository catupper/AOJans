#include<stdio.h>
#include<string.h>

int friend[502][502], ans[502];

void dfs(int x,int y){
  int i;
  ans[x] = 1;
  if(y == 0)return ;
  for(i = 1;i < 501;i++){
    if(friend[x][i]){
      dfs(i, y - 1);
    }
  }
}

int main(){
  while(1){
    int n, m, res = 0, i, j;
    scanf("%d%d",&n ,&m);
    if(n == 0 && m == 0)return 0;
    memset(friend, 0, sizeof(friend));
    memset(ans, 0, sizeof(ans));
    for(i = 0;i < m;i++){
      int a, b;
      scanf("%d%d", &a, &b);
      friend[a][b] = 1;
      friend[b][a] = 1;
    }
    dfs(1, 2);
    for(i = 2;i <= n;i++){
      res += ans[i];
    }
    printf("%d\n", res);
  }
}
