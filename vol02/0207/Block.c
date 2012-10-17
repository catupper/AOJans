#include<stdio.h>
#include<string.h>

int w, h, xs, ys, xg, yg, board[105][105], start_color;

int dfs(int x, int y){
  int i;
  if(board[x][y] != start_color)return 0;
  if(x == xg && y == yg)return 1;
  board[x][y] = 0;
  int xi[] = {0, 1, 0, -1}, yi[] = {1, 0, -1, 0};
  for(i = 0;i < 4;i++)
    if(dfs(x + xi[i], y + yi[i]))
      return 1;

  return 0;
}

int main(){
  int n, c, d, x, y, i, j;
  while(1){
    memset(board, 0, sizeof(board));
    scanf("%d%d", &w, &h);
    if(w == 0 && h == 0)return 0;
    scanf("%d%d", &xs, &ys);
    scanf("%d%d", &xg, &yg);
    scanf("%d", &n);
    while(n--){
      scanf("%d%d%d%d", &c, &d, &x, &y);
      if(d == 1){
	for(i = x;i < x + 2;i++)
	  for(j = y;j < y + 4;j++)
	    board[i][j] = c;
      }
      if(d == 0){
	for(i = x;i < x + 4;i++)
	  for(j = y;j < y + 2;j++)
	    board[i][j] = c;
      }
    }
    start_color = board[xs][ys];
    if(start_color != 0 && dfs(xs, ys))
      puts("OK");
    else
      puts("NG");
  }
}
