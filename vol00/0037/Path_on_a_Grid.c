#include<stdio.h>

int wall[15][15], x, y, way, i, j, anyway;

int main(){
  for(i = 1;i <= 9;i++){
    for(j = 1;j <= 5 - (i % 2);j++){
      scanf("%1d", &wall[i][j]);
    }
  }
  x = 0;
  y = 0;
  way = 0;// 0:R, 1:D, 2:L, 3:U
  anyway = 0;
  do{
    if(way == 0){
      if(!anyway && wall[x * 2][y + 1] == 1){
	way = 3;
	anyway = 1;
      }
      else if(wall[x * 2 + 1][y + 1] == 1){
	y++;
	anyway = 0;
	putchar('R');
      }
      else{
	way = 1;
	anyway = 0;
      }
    }
    if(way == 1){
      if(!anyway && wall[x * 2 + 1][y + 1] == 1){
	way = 0;
	anyway = 1;
      }
      else if(wall[x * 2 + 2][y + 1] == 1){
	x++;
	anyway = 0;
	putchar('D');
      }
      else{
	way = 2;
	anyway = 0;
      }
    }
    if(way == 2){
      if(!anyway && wall[x * 2 + 2][y + 1] == 1){
	way = 1;
	anyway = 1;
      }
      else if(wall[x * 2 + 1][y] == 1){
        y--;
	anyway = 0;
	putchar('L');
      }
      else{
	way = 3;
	anyway = 0;
      }
    }
    if(way == 3){
      if(!anyway && wall[x * 2 + 1][y] == 1){
	way = 2;
	anyway = 1;
      }
      else if(wall[x * 2][y + 1] == 1){
	x--;
	anyway = 0;
	putchar('U');
      }
      else{
	way = 0;
	anyway = 0;
      }
    }
  }while(x != 0 || y != 0);
  puts("");
  return 0;
}
