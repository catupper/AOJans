#include<stdio.h>

#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)


int n, i, j, k, num[105][105], sum[105][105];

int main(){

    scanf("%d", &n);
    
    for(i = 1;i <= n;i++){
	for(j = 1;j <= n;j++){
	    scanf("%d", &num[i][j]);
	    sum[i][j] = sum[i][j - 1] + num[i][j];
	}
    }
    
    int ans = -(1 << 30);
    
    for(i = 0;i <= n;i++){
	for(j = i + 1;j <= n;j++){
	    int res = -(1 << 30);
	    for(k = 1;k <= n;k++){
		res = max(res + sum[k][j] - sum[k][i], sum[k][j] - sum[k][i]);
		ans = max(res, ans);
	    }
	}
    }
    
    printf("%d\n", ans);
    return 0;
}
