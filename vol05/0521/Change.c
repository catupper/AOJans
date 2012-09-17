#include<stdio.h>

int main(){
  while(1){
    int n, i, res = 0;
    int coin[] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &n);
    if(n == 0){
      return 0;
    }
    n = 1000 - n;
    for(i = 0;i < 6;i++){
      res += n / coin[i];
      n %= coin[i];
    }
    printf("%d\n",res);
  }
}
