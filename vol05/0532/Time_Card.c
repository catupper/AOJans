#include<stdio.h>

int main(){
  int h1, m1, s1, h2, m2, s2, ans, i;
  for(i = 0;i < 3;i++){
    scanf("%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2);
    ans = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1); 
    printf("%d %d %d\n", ans / 3600, (ans / 60) % 60, ans % 60);
  }
  return 0;
}
