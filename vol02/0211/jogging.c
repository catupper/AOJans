#include<stdio.h>

long long gcd(long long a, long long b){
    if(a == 0)return b;
    return gcd(b % a, a);
}

long long lcm(long long *a, long long *b, long long x, long long y){
    long long d = gcd(x, y);
    x /= d;y /= d;
    *a = *a / gcd(*a, x) * x;
    *b = gcd(*b, y);
}

int main(){
    long long  d[15], v[15], i;
    int n;
    while(scanf("%d", &n), n){
	long long ga = 1, gb = 0;
	for(i = 0;i < n;i++){
	    scanf("%lld%lld", d + i, v + i);
	    lcm(&ga, &gb, d[i], v[i]);
	}
	for(i = 0;i < n;i++){
	    printf("%lld\n", v[i] * ga / gb / d[i]);
	}
    }
    return 0;
}
