#include<stdio.h>

int field[13][13], i, j, left, top;

int main(){
  while(1){
    left = top = -1;
    for(i = 1;i <= 8;i++){
      for(j = 1;j <= 8;j++){
	if(scanf("%1d", &field[i][j]) == EOF) return 0;
	if(field[i][j] == 1 && top == -1){
	  top = i;
	  left = j;
	}
      }
    }
    if(field[top][left + 1] == 1 && field[top + 1][left] == 1 && field[top + 1][left + 1] ==1)
      puts("A");

    if(field[top + 1][left] == 1 && field[top + 2][left] == 1 && field[top + 3][left] ==1)
      puts("B");

    if(field[top][left + 1] == 1 && field[top][left + 2] == 1 && field[top][left + 3] ==1)
      puts("C");

    if(field[top + 1][left - 1] == 1 && field[top + 2][left - 1] == 1 && field[top + 1][left] ==1)
      puts("D");

    if(field[top][left + 1] == 1 && field[top + 1][left + 1] == 1 && field[top + 1][left + 2] ==1)
      puts("E");

    if(field[top + 1][left] == 1 && field[top + 1][left + 1] == 1 && field[top + 2][left + 1] ==1)
      puts("F");

    if(field[top][left + 1] == 1 && field[top + 1][left] == 1 && field[top + 1][left - 1] ==1)
      puts("G");    
  }
}
