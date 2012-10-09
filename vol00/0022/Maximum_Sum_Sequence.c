#include<stdio.h>
#define INF (1 << 30)
#define max(x, y) ((x) > (y) ? (x) : (y))
int main(){
  int sums[5005], n, i, j, a, ans;
  while(1){
    ans = -INF;
    scanf("%d", &n);
    if(n == 0)return 0;
    sums[0] = 0;
    for(i = 1;i <= n;i++){
      scanf("%d" , &a);
      sums[i] = sums[i - 1] + a;
    }
    for(i = 1;i <= n;i++){
      for(j = i;j <= n;j++){
	ans = max(ans, sums[j] - sums[i - 1]);
      }
    }
    printf("%d\n", ans);
  }
}
