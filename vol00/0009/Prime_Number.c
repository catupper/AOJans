#include<stdio.h>

int prime[1000005];

int main(){
  int i, j, n, ans;
  for(i = 2;i <= 1000;i++){
    if(prime[i] == 1)continue;
    else{
      for(j = i * i;j < 1000000;j += i)
	prime[j] = 1;
    }
  }
  while(scanf("%d", &n) != EOF){
    ans = 0;
    for(i = 2;i <= n;i++){
      if(prime[i] == 0)ans++;
    } 
    printf("%d\n", ans);
  }
  return 0;
}
