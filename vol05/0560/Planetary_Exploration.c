#include<stdio.h>

int field[3][1001][1001];
int main(){
  int n, m, k, i, j;
  scanf("%d%d%d", &n, &m, &k);
  for(i = 1;i <= n;i++){
    for(j = 1;j <= m;j++){
      char c;
      scanf(" %c", &c);
      int check[] = {0, 0, 0}, p;
      if(c == 'J')check[0]++;
      if(c == 'O')check[1]++;
      if(c == 'I')check[2]++;
      for(p = 0;p < 3;p++){
	field[p][i][j] = field[p][i - 1][j] + field[p][i][j - 1] - field[p][i - 1][j - 1] + check[p];
      }
    }
  }
  for(i = 0;i < k;i++){
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;y1--;
    printf("%d %d %d\n", field[0][x2][y2] - field[0][x2][y1] - field[0][x1][y2] + field[0][x1][y1], 
			 field[1][x2][y2] - field[1][x2][y1] - field[1][x1][y2] + field[1][x1][y1], 
			 field[2][x2][y2] - field[2][x2][y1] - field[2][x1][y2] + field[2][x1][y1]);
  }  
  return 0;
							      
}
