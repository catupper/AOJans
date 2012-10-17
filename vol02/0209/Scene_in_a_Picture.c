#include<stdio.h>
#define INF (1 << 25)
int field[100][100], pict[50][50], n, m, ansx, ansy;

int mach(int x, int y, int k){
  int firstx = -1, firsty = -1, match = 1, i, j;

  for(i = 0;i < m && match;i++){
    for(j = 0;j < m && match;j++){
      if(k == 0 && pict[i][j] == -1)continue;
      if(k == 1 && pict[j][m - i - 1] == -1)continue;
      if(k == 2 && pict[m - j - 1][i] == -1)continue;
      if(k == 3 && pict[m - i - 1][m - j - 1] == -1)continue;
      if(firstx == -1){
	firstx = i + x;
	firsty = j + y;
      }
      if(k == 0 && field[x + i][y + j] != pict[i][j])
	match = 0;
      if(k == 1 && field[x + i][y + j] != pict[j][m - i - 1])
	match = 0;
      if(k == 2 && field[x + i][y + j] != pict[m - j - 1][i])
	match = 0;
      if(k == 3 && field[x + i][y + j] != pict[m - i - 1][m - j - 1])
	match = 0;
    } 
  }  
  if(match)
    if(ansx > firstx + 1){
      ansx = firstx + 1;
      ansy = firsty + 1;
    }
    else if(ansx == firstx + 1 && ansy > firsty + 1){
      ansx = firstx + 1;
      ansy = firsty + 1;
    }

  return match;
}

int main(){
  int i, j, k;
  while(1){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    ansx = ansy = INF;
    for(i = 0;i < n;i++)
      for(j = 0;j < n;j++)
	scanf("%d", &field[i][j]);
    
    for(i = 0;i < m;i++)
      for(j = 0;j < m;j++)
	scanf("%d", &pict[i][j]);

    for(i = 0;i + m - 1 < n;i++){
      for(j = 0;j + m - 1 < n;j++){
	for(k = 0;k < 4;k++){
	  mach(i, j, k);
	}
      }
    }
    if(ansx == INF)
      puts("NA");
    else
      printf("%d %d\n", ansy, ansx);
  }
}
