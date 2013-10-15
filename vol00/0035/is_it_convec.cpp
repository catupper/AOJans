#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct P{
    P(double a, double b){
	x = a;y = b;
    }
    double x, y;
    double det(P a){
	return x * a.y - y * a.x;
    }
    P operator-(P a){
	return P(x - a.x, y - a.y);
    }
};

int main(){
    double xa, ya ,xb, yb, xc, yc, xd, yd;
    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd)){
	P a = P(xa, ya);
	P b = P(xb, yb);
	P c = P(xc, yc);
	P d = P(xd, yd);
	P ab = b - a;
	P bc = c - b;
	P cd = d - c;
	P da = a - d;
	if((ab.det(bc) <= 0) == (bc.det(cd) <= 0) && (bc.det(cd) <= 0) == (cd.det(da) <= 0) && (cd.det(da) <= 0) == (da.det(ab) <= 0)){
	    cout << "YES" << endl;
	}
	else{
	    cout << "NO" << endl;
	}
    }
}
