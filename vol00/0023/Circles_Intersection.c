#include<stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

int main(){
  int n, res;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);
  while(n--){
    res = 1;
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dist = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    if(dist > (ra + rb) * (ra + rb))res = 0;
    if(dist < (ra - rb) * (ra - rb)){
      if(ra > rb)res = 2;
      else res = -2;
    }
    printf("%d\n", res);  
  }
  return 0;
}
