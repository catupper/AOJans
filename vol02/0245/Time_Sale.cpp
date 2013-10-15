#include<iostream>
#include<algorithm>

using namespace std;
#define INF (1 << 30)
int xs[] = {0, 1, 0, -1}, ys[] = {1, 0, -1, 0};
int x, y, dp[10][21][21][1 << 10];
int g[10], d[10], s[10], e[10], n;
char c[21][21];
int sale[10][105];
int main(){
    while(cin >> x >> y, x | y){
	for(int i = 0;i < y;i++)
	    for(int j = 0;j < x;j++)
		for(int k = 0;k < (1 << 8);k++)
		    dp[0][i][j][k] = -INF;
	for(int i = 0;i < y;i++){
	    for(int j = 0;j < x;j++){
		cin >> c[i][j];
		if(c[i][j] == 'P'){
		    c[i][j] = '.';
		    dp[0][i][j][0] = 0;
		}
	    }
	}
	cin >> n;
	int used[10];
	fill(used, used + 10, 0);
	for(int i = 0;i < 10;i++)
	    for(int j = 0;j < 105;j++)
		sale[i][j] = 0;
	for(int i = 0;i < n;i++){
	    cin >> g[i] >> d[i] >> s[i] >> e[i];
	    used[g[i]] = 1;
	}
	for(int i = 1;i < 10;i++)used[i] += used[i - 1];
	for(int i = 0;i < n;i++){
	    for(int j = s[i];j <= e[i];j++)
		sale[used[g[i]] - 1][j] = d[i];
	}
	for(int i = 0;i < y;i++)
	    for(int j = 0;j < x;j++){
		if(c[i][j] != '.')c[i][j] = '0' + used[c[i][j] - '0'] - 1;
	    }
	int ans = 0;
	for(int i = 0;i <= 100;i++){
	    for(int j = 0;j < y;j++){
		for(int k = 0;k < x;k++){
		    if(c[j][k] != '.')continue;
		    int there = 0;
		    for(int l = 0;l < (1 << 8);l++){
			if(i){
			    dp[i & 1][j][k][l] = -INF;
			    for(int m = 0;m < 4;m++){
				int ty = j + ys[m], tx = k + xs[m];
				if(ty < 0 || ty >= y || tx < 0 || tx >= x)continue;
				if(c[ty][tx] == '.')
				    dp[i & 1][j][k][l] = max(dp[(i + 1) & 1][ty][tx][l], dp[i & 1][j][k][l]);
			    }
			}
			for(int m = 0;m < 4;m++){
			    int ty = j + ys[m], tx = k + xs[m];
			    if(ty < 0 || ty >= y || tx < 0 || tx >= x)continue;
			    if(c[ty][tx] == '.')continue;
			    int pr = c[ty][tx] - '0';
			    if(l & (1 << pr)){
				dp[i & 1][j][k][l] = max(dp[i & 1][j][k][l], dp[i & 1][j][k][l - (1 << pr)] + sale[pr][i]);
			    }
			}
			ans = max(dp[i & 1][j][k][l], ans);
		    }
		}
	    }
	}
	cout << ans << endl;
    }
}
