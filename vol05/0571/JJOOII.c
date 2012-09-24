#include<stdio.h>

int main(){
  int J, O, I, ans = 0;;
  char c = getchar();
  while(c == 'J' || c == 'O' || c == 'I'){
    J = O = I = 0;
    while(c == 'J'){
      J++;
      c = getchar();
    }
    while(c == 'O'){
      O++;
      c = getchar();
    }
    while(c == 'I'){
      I++;
      c = getchar();
    }
    if(O <= J && O <= I && O > ans){
      ans = O;
    }
  }
  printf("%d\n", ans);
  return 0;
}
