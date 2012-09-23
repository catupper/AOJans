#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  while(1){
    int d, n, m, res = 0;
    scanf("%d%d%d", &d, &n, &m);
    if(d == 0)return 0;
    int shop[n + 1];
    for(int i = 1;i < n;i++){
      scanf("%d", shop + i);
    }
    shop[n] = d;
    sort(shop, shop + n + 1);
    for(int i = 0;i < m;i++){
      int k;
      scanf("%d", &k);
      if(k == 0)continue;
      int * x = lower_bound(shop, shop + n, k);
      int * y = x - 1;
      res += min(*x - k,k - *y);
    }
    printf("%d\n", res);

  }
}
