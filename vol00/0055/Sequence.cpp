#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    double a, res;
    while(cin >> a){
	res = a;
	for(int i = 2;i <= 10;i++){
	    if(i % 2 == 0)a *= 2;
	    else a/=3;
	    res += a;
	}
	printf("%.9lf\n", res);
    }
    return 0;
}
