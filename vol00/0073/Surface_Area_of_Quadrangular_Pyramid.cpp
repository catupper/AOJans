#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double x, h;
    while(cin >> x >> h, x != 0 || h != 0){
	printf("%.9lf\n", x * x + 2 * x * hypot(x / 2, h));
    }
    return 0;
}
