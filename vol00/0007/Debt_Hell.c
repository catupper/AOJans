#include<stdio.h>

int main(){
  int i, n, money = 100000;
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    money += money / 20;
    if(money % 1000 != 0){
      money = (money / 1000 + 1) * 1000;
    }
  }
  printf("%d\n", money);
  return 0;
}
