#include<stdio.h>

int main(){
  int n, m, i;
  while(1){
    scanf("%d %d", &n, &m);
    int board[1000], walk, pos = 0, res = 0;
    if(n == 0)return 0;
    for(i = 0;i < n;i++){
      scanf("%d", board + i);
    }
    for(i = 0;i < m;i++){
      scanf("%d", &walk);
      if(pos >= n - 1)continue;
      pos += walk;
      if(pos < n - 1){
	pos += board[pos];
      }
      if(pos >= n - 1){
	printf("%d\n", i + 1);
      }
    }
  }
}
