#include<stdio.h>
#include<algorithm>
using namespace std;
#define MOD 100000007;

int conbis[3000][3000];

int conbination(int a, int b){
  if(conbis[a][b] != 0)return conbis[a][b];
  if(a == b || b == 0)return conbis[a][b] = 1;
  conbis[a][b] = (conbination(a - 1, b) + conbination(a - 1, b - 1)) % MOD;
  return conbis[a][b];
}

int main(){
  int r, c, a1, a2, b1, b2, x, y;
  scanf("%d%d%d%d%d%d", &r, &c, &a1, &a2, &b1, &b2);
  long long int ans = 1;
  x = abs(a1 - b1);
  x = min(x, r - x);
  y = abs(a2 - b2);
  y = min(y, c - y);
  if(r % 2 == 0 && r / 2 == x)
    ans *= 2;
  if(c % 2 == 0 && c / 2 == y)
    ans *= 2;
  ans *= conbination(x + y, y);
  ans %= MOD;
  printf("%lld\n", ans);
}
