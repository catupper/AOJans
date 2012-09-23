#include<stdio.h>
#include<string.h>

long long int mob[101][4];

long long int gcd(long long int x, long long int y){
  if(x == 0)return y;
  else return gcd(y % x, x);
}

long long int lcf(long long int x, long long int y){
  return (x * y) / gcd(x, y);
}

long long int dfs(int x){
  if(x == 0)return 1;
  long long int r = mob[x][0] * dfs(mob[x][2]);
  long long int b = mob[x][1] * dfs(mob[x][3]);
  long long int m = lcf(r, b);
  return m / mob[x][0] +  m / mob[x][1];
  
}

int main(){
  while(1){
    int n, i, notTop[101], top;
    memset(notTop, 0, sizeof(notTop));
    memset(mob, 0, sizeof(mob));
    scanf("%d", &n);
    if(n == 0)return 0;
    for(i = 1;i <= n;i++){
      int p, q, r, b;
      scanf("%d%d%d%d", &p, &q, &r, &b);
      notTop[r] = notTop[b] = 1;
      mob[i][0] = p;
      mob[i][1] = q;
      mob[i][2] = r;
      mob[i][3] = b;
    }
    for(i = 1;i <= n;i++){
      if(notTop[i] == 0){
	top = i;
	break;
      }
    }
    printf("%lld\n", dfs(top));
  }
}
