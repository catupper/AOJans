#include<stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int main(){
  while(1){
    int n, k, i, sum = 0, ans = 0, nums[100000];
    scanf("%d%d", &n, &k);
    if(n ==0 && k == 0)return 0;
    for(i = 0;i < n;i++){
      scanf("%d", nums + i);
    }
    for(i = 0;i < k;i++){
      sum += nums[i];
    }
    ans = sum;
    for(i = k;i < n;i++){
      sum -= nums[i - k];
      sum += nums[i];
      ans = max(ans, sum);
    }
    printf("%d\n", ans);
  }
}
