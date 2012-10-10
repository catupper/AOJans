#include<stdio.h>
#include<string.h>
#define min(x, y) ((x) < (y) ? (x) : (y));
int main(){
  int n, i, j, max, field[1004][1004];
  char c;
  while(1){
    memset(field, 0, sizeof(field));
    scanf("%d", &n);
    if(n == 0)return 0;
    for(i = 1; i <= n;i++){
      for(j = 1;j <= n;j++){
	scanf(" %c", &c);
	field[i][j] = field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];
	if(c == '*')field[i][j]++;
      }
    }
    max = 0;
    for(i = 0;i < n;i++){
      for(j = 0;j < n;j++){
	int top = min(n - i, n - j);
	int bottom = 0;
	while(top - bottom > 1){
	  int k = (top + bottom) / 2;
	  if(field[i + k][j + k] + field[i][j] - field[i][j + k] - field[i + k][j] == 0)
	    bottom = k;
	  else
	    top = k;
	}
	if(field[i + top][j + top] + field[i][j] - field[i][j + top] - field[i + top][j] == 0)bottom = top;
	if(max < bottom)max = bottom;

      }
    }
    printf("%d\n", max);
  }
}
