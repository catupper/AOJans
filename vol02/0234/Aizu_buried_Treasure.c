#include<stdio.h>

int solve(int x, int y, int p = 0){
    int &res = dp[x][y];
    if(j == 0)return 0;
    if(res != -1 && p)return res;
    for(int i = x;i <= x + 1;i++)
	for(int j = x - 1;j <= x + 1;j++){
	    if(i < 0 || i >= w || j < 0 || j >= h)continue;
	    
	}
    
}

int main(){
    while(scanf("%d%d", &w, &h), w | h){
	scanf("%d%d%d", &f, &m, &o);
	memset(dig, 0, sizeof(dig));
	memset(dig, -1, sizeof(dp));
	for(int i = 1;i <= w;i++)
	    for(int j = 0;j < h;j++)
		scanf("%d", &dig[i][j]);
	int rem = solve(0, 0);
	if(rem == INF)puts("NA");
	else printf("%d\n", rem);
    }
    return 0;
}
