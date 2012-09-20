#include<stdio.h>
#define abs(x)  ((x) < 0 ? -(x) : (x))
int main(){
  int hotels[100002], n, m, i, res = 0, now = 1;
  hotels[1] = 0;
  scanf("%d%d",&n ,&m);
  for(i = 2;i <= n;i++){
    int si;
    scanf("%d", &si);
    hotels[i] = hotels[i - 1] + si;
  }
  for(i = 0;i < m;i++){
    int ai;
    scanf("%d", &ai);
    res += abs(hotels[now] - hotels[now + ai]);
    now += ai;
    res %= 100000;
  }
  printf("%d\n", res);
  return 0;
}
