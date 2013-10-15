#include<iostream>
#include<algorithm>

using namespace std;

struct L{
    L(){}
    L(double o, double p, double q, double r){
	xa = o;
	ya = p;
	xb = q;
	yb = r;
	a = r - p;
	b = o - q;
	c = -(a*o+b*p);
    }
    
    double f(double x, double y){
	return a*x + b*y + c;
    }
    double xa, ya, xb, yb, a, b, c;
};

bool cross(L a, L b){
    return (a.f(b.xa, b.ya) * a.f(b.xb, b.yb) < 0 && 
	    b.f(a.xa, a.ya) * b.f(a.xb, a.yb) < 0);
}

int main(){
    double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
    while(cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2){
	L a[4], b[4];
	a[0] = L(xa1, ya1, xa1, ya2);
	a[1] = L(xa1, ya2, xa2, ya2);
	a[2] = L(xa2, ya1, xa2, ya2);
	a[3] = L(xa2, ya1, xa1, ya1);
	b[0] = L(xb1, yb1, xb1, yb2);
	b[1] = L(xb1, yb2, xb2, yb2);
	b[2] = L(xb2, yb1, xb2, yb2);
	b[3] = L(xb2, yb1, xb1, yb1);
	bool res = (xa1 <= xb1 && xb1 <= xa2) && (ya1 <= yb1 && yb1 <= ya2);
	res = res || (xa1 <= xb1 && xb1 <= xa2) && (ya1 <= yb2 && yb2 <= ya2);
	res = res || (xa1 <= xb2 && xb2 <= xa2) && (ya1 <= yb2 && yb2 <= ya2);
	res = res || (xa1 <= xb2 && xb2 <= xa2) && (ya1 <= yb1 && yb1 <= ya2);
	res = res || (xb1 <= xa1 && xa1 <= xb2) && (yb1 <= ya1 && ya1 <= yb2);
	res = res || (xb1 <= xa1 && xa1 <= xb2) && (yb1 <= ya2 && ya2 <= yb2);
	res = res || (xb1 <= xa2 && xa2 <= xb2) && (yb1 <= ya2 && ya2 <= yb2);
	res = res || (xb1 <= xa2 && xa2 <= xb2) && (yb1 <= ya1 && ya1 <= yb2);
				
	for(int i = 0;i < 4;i++){
	    for(int j = 0;j < 4;j++){
		if(cross(a[i], b[j]))res = true;
	    }
	}
	if(res)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    }
    return 0;
}
