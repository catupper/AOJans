#include<stdio.h>

int main(){
    int i, j, n;
    int num[105][105];
    while(scanf("%d", &n), n){
	for(i = 0;i < n;i++)
	    for(j = 0;j < n;j++)
		scanf("%d", &num[i][j]);
	num[n][n] = 0;
	for(i = 0;i < n;i++){
	    num[i][n] = num[n][i] = 0;
	    for(j = 0;j < n;j++){
		num[i][n] += num[i][j];
		num[n][i] += num[j][i];
	    }
	    num[n][n] += num[i][n];
	}
	for(i = 0;i <= n;i++){
	    for(j = 0;j <= n;j++){
		printf("%5d", num[i][j]);
	    }
	    puts("");
	}
    }
    return 0;
}
