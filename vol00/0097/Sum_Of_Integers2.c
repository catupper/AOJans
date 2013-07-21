#include<stdio.h>
long long dp[105][15][1050];//count,sum
long long i, j, k, n, s;



int main(){
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for(i = 1;i < 105;i++){
	for(j = 0;j < 15;j++){
	    for(k = 0;k < 1050;k++){
		if(k - i >= 0 && j - 1 >= 0)
		    dp[i][j][k] = dp[i - 1][j - 1][k - i] + dp[i - 1][j][k];
		else
		    dp[i][j][k] = dp[i - 1][j][k];

	    }
	}
    }
    while(1){
	scanf("%lld%lld", &n, &s);
	if(n == 0 && s == 0)return 0;
	printf("%lld\n",dp[100][n][s]);
    }
    return 0;
}
