#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define EPS (1e-10)
int main(){
    double x1, y1, x2, y2, xq, yq;

    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq ,&yq)){
	double a = y1 - y2;
	double b = - x1 + x2;
	double c = -(a*x1 + b*y1);
	double dis = abs(a * xq + b * yq + c) / hypot(a, b);
	double xa = xq + 2 * dis * (y1 - y2) / hypot(x1 - x2, y1 - y2), xb = xq - 2 * dis * (y1 - y2) / hypot(x1 - x2, y1 - y2);
	double ya = yq + 2 * dis * (x2 - x1) / hypot(x1 - x2, y1 - y2), yb = yq - 2 * dis * (x2 - x1) / hypot(x1 - x2, y1 - y2);
	double disa = abs(a * xa + b * ya + c) / hypot(a, b);
	if(abs(dis - disa) < EPS){
	    printf("%.9lf %.9lf\n", xa, ya);
	}
	else{
	    printf("%.9lf %.9lf\n", xb, yb);
	}
    }
    return 0;
}
