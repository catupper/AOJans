
#include<stdio.h>

int main(){
  int n;
  double x1, x2, x3, x4, y1, y2, y3, y4;
  scanf("%d", &n);
  while(n--){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if((x1 - x2) * (y3 - y4) == (y1 - y2) * (x3 - x4))puts("YES");
    else puts("NO");
  }
  return 0;
}
