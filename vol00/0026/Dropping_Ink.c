#include<stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int field[14][14];

int main(){
  int x, y, size, maxs, ans, i, j;
  while(scanf("%d,%d,%d", &x, &y, &size) != EOF){
    x += 2;
    y += 2;
    if(size == 1){
      field[x][y]++;
      field[x + 1][y]++;
      field[x][y + 1]++;
      field[x - 1][y]++;
      field[x][y - 1]++;
    }
    if(size == 2){
      field[x][y - 1]++;
      field[x][y]++;
      field[x][y + 1]++;
      field[x + 1][y - 1]++;
      field[x + 1][y]++;
      field[x + 1][y + 1]++;
      field[x - 1][y - 1]++;
      field[x - 1][y]++;
      field[x - 1][y + 1]++;
    }
    if(size == 3){
      field[x][y - 1]++;
      field[x][y]++;
      field[x][y + 1]++;
      field[x + 1][y - 1]++;
      field[x + 1][y]++;
      field[x + 1][y + 1]++;
      field[x - 1][y - 1]++;
      field[x - 1][y]++;
      field[x - 1][y + 1]++;
      field[x + 2][y]++;
      field[x][y + 2]++;
      field[x - 2][y]++;
      field[x][y - 2]++;
    }
  }
  for(i = 2;i < 12;i++){
    for(j = 2;j < 12;j++){
      if(field[i][j] == 0)ans++;
      maxs = max(maxs, field[i][j]);
    }
  }
  printf("%d\n%d\n", ans, maxs);
  return 0;
}
