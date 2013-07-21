#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    int n;
    double x1, x2, x3, y1, y2, y3, x, y;
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if(y1 == y2)swap(x1, x3), swap(y1, y3);
	else if(y1 == y3)swap(x1, x2), swap(y1, y2);
	double x = (x3-x1)/(y1-y3)*(x1+x3)/2-(x2-x1)/(y1-y2)*(x1+x2)/2+(y1+y2)/2-(y1+y3)/2;
	x /= ((x3-x1)/(y1-y3) - (x2-x1)/(y1-y2));
	double y = (x2-x1)/(y1-y2)*(x - (x1+x2)/2) + (y1+y2)/2;
	printf("%.3lf %.3lf %.3lf\n", x, y, hypot(x1-x,y1-y));
    }
    return 0;
}
