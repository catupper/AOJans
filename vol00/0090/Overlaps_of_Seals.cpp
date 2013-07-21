#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define EPS (1e-10)
double x[1050], y[1050];
int n;

int count(int a, int b){
    double tx = (x[a] + x[b]) / 2;
    double ty = (y[a] + y[b]) / 2;
    double dx = (y[a] - y[b]);
    double dy = (x[b] - x[a]);
    double rat =  sqrt(1 - (dy * dy + dx * dx) / 4)/ hypot(dx, dy);
    dx *= rat;
    dy *= rat;
    tx += dx;
    ty += dy;
    int res = 0;
    for(int i = 0;i < n;i++){
	if(hypot(x[i] - tx, y[i] - ty) <= 1 + EPS)res++;
    }
    return res;
}

int main(){
    while(1){
    int res = 1;
	cin >> n;
	if(n == 0)return 0;
	for(int i = 0;i < n;i++){
	    scanf("%lf,%lf", &x[i], &y[i]);
	}
	for(int i = 0;i < n;i++){
	    for(int j = i + 1;j < n;j++){
		if(hypot(x[i] - x[j], y[i] - y[j]) <= 2 + EPS){
		    res = max(res, count(i, j));
		    res = max(res, count(j, i));
		}
	    }
	}
	cout << res << endl;
    }
}
