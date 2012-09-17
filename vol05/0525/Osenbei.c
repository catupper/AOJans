#include<stdio.h>

int main(){
  while(1){
    int c, r, i, j, k;
    int field[10][10000], res = 0;
    scanf("%d%d", &c, &r);
    if(c == 0 && r == 0){
      return 0;
    }
    for(i = 0;i < c;i++){
      for(j = 0;j < r;j++){
	scanf("%d", field[i] + j);
      }
    }
    for(i = 0;i < 1 << c;i ++){
      int sum = 0;
      for(j = 0;j < r;j++){
	int col = 0;
	for(k = 0;k < c;k++){
	  int uragaesi = (i >> k) & 1;
	  if(field[k][j] == uragaesi){
	    col++;
	  }
	}
	if(c - col > col){
	  col = c - col;
	}
	sum += col;
      }
      if(res < sum){
	res = sum;
      }
    }
    printf("%d\n",res);
  }
}
