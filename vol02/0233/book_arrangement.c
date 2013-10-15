#include<stdio.h>

#define abs(a) ((a) < 0?(-(a)):(a))

long long solve(int x){
    int ans[] = {9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0};
    long long now = -909090909090;
    now = (long long)x - now;
    int p = 11, i;
    while(now){
	ans[p] = abs(ans[p] - (now % 10));
	p--;now/=10;
    }
    char res[100];
    for(i = 0;i < 12;i++)res[i] = ans[i] + '0';
    res[12] = 0;
    sscanf(res, "%lld", &now);
    return now;
}


int main(){
    int n;
    while(scanf("%d", &n), n)
	printf("%lld\n", solve(n));
    return 0;
}
