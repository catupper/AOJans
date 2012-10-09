#include<stdio.h>

int main(){
  int ans, d, i;
  while(scanf("%d", &d) != EOF){
    ans = 0;
    for(i = d;i != 600;i += d){
      ans += i * i * d; 
    }
    printf("%d\n", ans);
  }
  return 0;
}
