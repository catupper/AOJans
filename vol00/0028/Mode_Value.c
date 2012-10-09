#include<stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n[101], mx = 0;

int main(){
  int i;
  while(scanf("%d", &i) != EOF){
    n[i]++;
    mx = max(mx, n[i]);
  }
  for(i = 1;i <= 100;i++){
    if(n[i] == mx)
      printf("%d\n",i);
  }
  return 0;
}
