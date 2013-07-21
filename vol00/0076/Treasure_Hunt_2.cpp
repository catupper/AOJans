#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double x[1050], y[1050];
    x[1] = 1, y[1] = 0;
    for(int i = 2;i < 1050;i++){
	double s = hypot(x[i - 1], y[i - 1]);
	x[i] = x[i - 1] - 1/s * y[i - 1];
	y[i] = y[i - 1] + 1/s * x[i - 1];
    }
    int n;
    while(cin >> n, n != -1){
	printf("%.9lf\n", x[n]);
	printf("%.9lf\n", y[n]);
    }
    return 0;
}
