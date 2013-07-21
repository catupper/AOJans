#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    vector<double> x, y;
    double a, b, c, s;
    while(~scanf("%lf,%lf", &a, &b)){
	x.push_back(a);
	y.push_back(b);
    }
    for(int i = 1;i <= x.size();i++){
	x[i%x.size()] -= x[0];
	y[i%x.size()] -= y[0];
    }
    double res = 0;
    for(int i = 1;i < x.size() - 1;i++){
	res += fabs(x[i] * y[i + 1] - y[i] * x[i + 1]);
    }
    printf("%.9lf\n", res / 2);
    return 0;
}
