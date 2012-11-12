#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
  int s[551], minus = 0, n;
  long long int res = 1;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
    scanf("%d", s + i);
  sort(s, s + n);
  for(int i = n - 1;i >= 0;i--,minus++){
    res += max(0, s[i] - minus / 4);
  }
  printf("%lld\n", res );
  return 0;
}
