#include<stdio.h>

int main(){
  while(1){
    int n, i, j, k;
    int card[201], player[2], turn = 0, ba = 0;
    for(i = 0;i < 201;i++){
      card[i] = 1;
    }
    card[0] = 2;
    scanf("%d", &n);
    if(n == 0){
      return 0;
    }
    player[0] = player[1] = n;
    for(i = 0;i < n;i++){
      scanf("%d", &j);
      card[j] = 0;
    }
    while(player[0] != 0 && player[1] != 0){
      for(;ba <= 2 * n;ba++){
	if(card[ba] == turn){
	  card[ba] = 2;
	  player[turn]--;
	  break;
	}
      }
      if(ba == 2 * n + 1){
	ba = 0;
      }
      turn ^= 1;
    }
    printf("%d\n%d\n", player[1], player[0]);
  }
}
