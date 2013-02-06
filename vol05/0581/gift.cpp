#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#define INF (1 << 30)
#define all ((1 << 12) - 1)

int xs[] = {0, -1, 0, 1}, ys[] = {-1, 0, 1, 0};
int h, w, k;
int dp[52][52][4][1 << 12];
string port[52];

bool back(int last){
    int p = 0, q = 0;
    for(int i = 0;i < 6;i++){
	p += xs[last % 4];
	q += ys[last % 4];
	if(p == 0 && q == 0)return true;
	last >>= 2;
    }
    return false;
}

int solve(int x, int y, int d, int last){
    if(x == 0 && y == 0 && d == 0)return 0;
    if(x < 0 || x >= h || y < 0 || y >= w || d < 0)return -INF;
    if(dp[x][y][d][last] != -INF)return dp[x][y][d][last];
    if(port[x][y] == '#')return -INF;
    int add = 0, res = -INF;
    if(port[x][y] != '.' && !back(last))add = port[x][y] - '0';
    for(int i = 0;i < 4;i++){
	x += xs[i];y += ys[i];
	if(i == 2)d--;
	res = max(res, solve(x, y, d, all & ((last << 2) + i)));
	x -= xs[i];y -= ys[i];	   
    }
    d++;
    return dp[x][y][d][last] = res + add;
}

int main(){
    cin >> h >> w >> k;
    for(int i = 0;i < h;i++){
	cin >> port[i];
	for(int j = 0;j < w;j++){
	    for(int k = 0;k <= 3;k++){
		fill(dp[i][j][k], dp[i][j][k] + (1 << 12), -INF);
	    }
	}
    }
    int res = -INF;
    for(int i = 0;i <= k;i++){
	res = max(res, solve(h - 1, w - 1, i, 0));
    }
    cout << res << endl;
    return 0;
}
