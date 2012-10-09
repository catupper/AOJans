#include<stdio.h>
#include<string.h>

int main(){
  int n ,ans[100], agari, i, j, ap, bp;
  char a[1000], b[1000];
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%s%s", a, b);
    if(strlen(a) > 80 || strlen(b) > 80){
      puts("overflow");
      continue;
    }
    ap = strlen(a) - 1;
    bp = strlen(b) - 1;
    j = 0;
    agari = 0;
    while(ap >= 0 || bp >= 0){
      ans[j] = agari;
      if(ap >= 0)ans[j] += a[ap] - '0';
      if(bp >= 0)ans[j] += b[bp] - '0';
      agari = ans[j] / 10;
      ans[j] %= 10;
      j++;
      ap--;
      bp--;

    }
    if(agari == 1)ans[j] = 1;
    else j--;
    if(j >= 80){
      puts("overflow");
      continue;
    }
    for(;j >= 0;j--){
      printf("%d", ans[j]);
    }
    puts("");
  }
  return 0;
}
