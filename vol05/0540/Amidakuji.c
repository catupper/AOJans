#include<stdio.h>
#include<string.h>
#define min(x,y) ((x) < (y) ? (x) : (y))
void swap(int* x, int* y){
  int l = *x;
  *x = *y;
  *y = l;
}

int main(){
  while(1){
    int n, m, h, k;
    int i, j;
    int last[1001], amida[1001][1001], now[1001], before[1001], change[100001][2];
    memset(amida, 0, sizeof(amida));
    scanf("%d%d%d%d", &n, &m, &h, &k);
    if(n == 0 && m == 0 && h == 0 && k == 0)return 0;
    for(i = 0;i < n;i++){
      scanf("%d", last + i);
      now[i] = i;
    }
    for(i = 0;i < m;i++){
      int a, b;
      scanf("%d%d", &a, &b);
      amida[b][a - 1] = 1;
    }
    int cnt = 0;
    for(i = 0;i <= h;i++){
      for(j = 0;j < n;j++){
	if(amida[i][j]){
	  swap(&now[j], &now[j + 1]);
	  change[cnt][0] = now[j];
	  change[cnt][1] = now[j + 1];
	  cnt++;
	}
      }
    }
    int none = 0;
    int ans = 0;
    for(i = 0;i < n;i++){
      before[now[i]] = i;
    }
    for(i = 0;i < k;i++){
      none += last[before[i]];
    }
    ans = none;
    for(i = 0;i < cnt;i++){
      int x = change[i][0];
      int y = change[i][1];
      if(x > y) swap(&x, &y);
      if(x >= k && y >= k)continue;
      if(x < k && y < k)continue;
      ans = min(ans, none - last[before[x]] + last[before[y]]);
    }
    printf("%d\n", ans);
  }
}
