#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> P;
#define INF (1 << 30)
int nowmax = INF, x, y;
char c;
int come[10][10];
int xs[] = {1, 0, -1, 0}, ys[] = {0, 1, 0, -1};
int dfs(int color[][10], int count = 0){
    int res = nowmax;
    if(count >= res)return INF;
    for(int i = 0;i < 3;i++){
	if(i == color[0][0])continue;
	int tmp[10][10];
	int done = 1;
	for(int j = 0;j < y;j++)
	    for(int k = 0;k < x;k++){
		tmp[j][k] = color[j][k];
		if(tmp[j][k] != color[0][0])done = 0;
		come[j][k] = 0;
	    }
	if(done){
	    nowmax = min(nowmax, count);
	    return count;
	}
	queue<P> q;
	q.push(P(0, 0));
	int ok = 0;
	while(!q.empty()){
	    for(int j = q.size();j > 0;j--){
		P t = q.front();q.pop();
		int a = t.first, b = t.second;
		if(come[a][b])continue;come[a][b] = 1;
		if(tmp[a][b] == i)ok = 1;
		if(tmp[a][b] != color[0][0])continue;
		tmp[a][b] = i;
		for(int k = 0;k < 4;k++){
		    int tx = b + xs[k], ty = a + ys[k];
		    if(tx < 0 || tx >= x || ty < 0 || ty >= y)continue;
		    q.push(P(ty, tx));
		}
	    }
	}
	if(ok){
	    res = min(res, dfs(tmp, count + 1));
	    nowmax = min(res, nowmax);
	}
    }
    return res;
}

int main(){
    int color[10][10];
    while(cin >> x >> y, x|y){
	for(int i = 0;i < y;i++)
	    for(int j = 0;j < x;j++){
		cin >> c;
		if(c == 'R')color[i][j] = 0;
		if(c == 'G')color[i][j] = 1;
		if(c == 'B')color[i][j] = 2;
						
	    }
	nowmax = INF;
	cout << dfs(color) << endl;
    }
    return 0;
}
