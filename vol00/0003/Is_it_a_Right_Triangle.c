#include<stdio.h>

int main(){
  int i, n, a, b, c;
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d%d%d", &a, &b, &c);
    a *= a;
    b *= b;
    c *= c;
    if(a + b == c || a + c == b || b + c == a)puts("YES");
    else puts("NO");
  }
  return 0;
}
