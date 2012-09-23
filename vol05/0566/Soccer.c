#include<stdio.h>

int points[101];

int main(){
  int n, i, j;
  scanf("%d", &n);
  for(i = 0;i < n * (n - 1) / 2;i++){
    int ai, bi, ci, di;
    scanf("%d%d%d%d", &ai, &bi, &ci, &di);
    if(ci == di){
      points[ai]++;
      points[bi]++;
    }
    else if(ci > di){
      points[ai] += 3;
    }
    else{
      points[bi] += 3;
    }
  }
  for(i = 1;i <= n;i++){
    int res = 1;
    for(j = 1;j <= n;j++){
      if(points[j] > points[i])res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
