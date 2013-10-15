#include<stdio.h>

#define INF (1 << 30)

#define abs(a) ((a)<0?(-(a)):(a))
#define min(a, b) ((a)<(b)?(a):(b))

int i, j, p[105], t[105], dp[105][5], n, ng, ok, ans;

int main(){
    while(scanf("%d", &n), n){
	for(i = 0;i < n;i++){
	    scanf("%d%d", p + i, t + i);
	}
	dp[0][0] = dp[0][1] = dp[0][2] = p[0];
	if(p[0] > t[0]){
	    ng = 1;
	    ok = 0;
	    goto fin;
	}
	for(i = 1;i < n;i++){
	    ok = 0;
	    dp[i][0] = dp[i][1] = dp[i][2] = INF;
	    for(j = 0;j < 3;j++){
		if(t[i - 1] + p[i - 1] * (j + 2) + p[i] < t[i]){
		    dp[i][0] = min(dp[i][0], dp[i - 1][j] + p[i - 1] + p[i]);
		    ok |= dp[i][0] != INF;
		}
		if(j == 0)continue;
		if(t[i - 1] + abs(p[i - 1] - p[i]) * (j + 1) < t[i]){
		    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(p[i - 1] - p[i]));
		    ok |= dp[i][j] != INF;
		}
	    }
	    if(ok)continue;
	    ng = i + 1;
	    break;
	}
    fin:
	if(ok){
	    ans = INF;
	    ans = min(ans, dp[n - 1][0]);
	    ans = min(ans, dp[n - 1][1]);
	    ans = min(ans, dp[n - 1][2]);
	    printf("OK %d\n", ans + p[n - 1]);
	}
	else{
	    printf("NG %d\n", ng);
	}
    }
    return 0;
}
