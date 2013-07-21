#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define ABS(a) ((a)<0?(-(a)):(a))

int main(){
    while(1){
	double q;
	cin >> q;
	if(q == -1)return 0;
	double a = q / 2;
	while(true){
	    a = a - (a*a*a - q)/(3*a*a);
	    if(ABS(a * a * a - q) < q * 0.00001)break;
	}
	printf("%.9lf\n", a);
    }
}
