#include<stdio.h>

int main(){
  long long int  res = 1;
  int n;
  scanf("%d", &n);
  for(;n >= 1;n--){
    res *= n;
  }
  printf("%lld\n", res);
  return 0;
}
