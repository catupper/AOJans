#include<stdio.h>


int main(){
  int n, m, i, j, card[200], card2[200];
  scanf("%d%d", &n, &m);
  for(i = 0;i < 2 * n;i++)card[i] = i + 1;
  for(j = 0;j < m;j++){
    int cut;
    scanf("%d", &cut);
    if(cut == 0){
      for(i = 0;i < n;i ++){
	card2[i * 2] = card[i];
	card2[i * 2 + 1] = card[i + n];
      }
    }
    else{
      for(i = 0;i + cut < 2 * n;i++){
	card2[i] = card[i + cut];
      }
      for(i = 0;i < cut;i++){
	card2[2 * n - cut + i] = card[i];
      }
    }
    for(i = 0;i < 2 * n;i++){
      card[i] = card2[i];
    }
  }
  for(i = 0;i < 2 * n;i++){
    printf("%d\n", card[i]);
  }
  return 0;
}
