#include<stdio.h>
#define min(x,y) ((x) < (y) ? (x) : (y))


int main(){
  int n, k, i;
  scanf("%d %d", &n, &k);
  for(i = 0;i < k;i++){
    int x, y;
    scanf("%d%d", &x, &y);
    x = min(x, n + 1 - x);
    y = min(y, n + 1 - y);
    printf("%d\n", (min(x, y) - 1) % 3 + 1);    
  }
  return 0;
}
