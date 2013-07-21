#include<stdio.h>
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))
long long d[2100];
long long n, i;

int main(){
    for(i = 0;i <= 2000;i++){
	d[i] = min(1000, i - 0) - max(0, i - 1000) + 1;
    }
    while(scanf("%lld", &n) != EOF){
	long long res = 0;
	for(i = 0;i <= min(n, 2000);i++){
	    int p = n - i;
	    if(p > 2000)continue;
	    res += d[i] * d[p];
	}
	printf("%lld\n", res);
    }
    return 0;
}
