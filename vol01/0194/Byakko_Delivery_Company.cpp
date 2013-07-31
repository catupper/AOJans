#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;
#define INF (1 << 25)

typedef pair<int, int> P;
typedef pair<P, int> N;
typedef pair<int, N> T;

int dist[25][25][25][25];
int dkst[25][25][2];
int light[25][25];
int ys[]={0, 1, 0, -1}, xs[]={1, 0, -1, 0};
    int m, n, d, ns, ya, yb, k;
char xa, xb;
int nc, nj;

void dijkstra(P start){
    priority_queue<T, vector<T>, greater<T> > pq;
    dkst[start.first][start.second][1] = 0;
    pq.push(T(0, N(start, 0)));
    while(!pq.empty()){
	T tmp = pq.top();pq.pop();
	int d = tmp.first, x = tmp.second.first.first, y = tmp.second.first.second, k = light[x][y], w = tmp.second.second;
	if(dkst[x][y][w] < d)continue;
	if(k != 0){
	    if(w == 0)while(d % (k * 2) >= k)d++;
	    else while(d % (k * 2) < k)d++;
	}
	for(int i = 0;i < 4;i++){
	    int tx = x + xs[i], ty = y + ys[i];
	    if(tx < 0 || tx >= m || ty <= 0 || ty > n)continue;
	    if(dkst[tx][ty][i % 2] <= d + dist[x][y][tx][ty])continue;
	    dkst[tx][ty][i % 2] = d + dist[x][y][tx][ty];
	    pq.push(T(dkst[tx][ty][i % 2], N(P(tx, ty), i % 2)));
	}
    }
}

int main(){
    while(cin >> m >> n, m | n){
	cin >> d >> ns;
	for(int i = 0;i < 25;i++)for(int j = 0;j < 25;j++)for(int k = 0;k < 25;k++)for(int l = 0;l < 25;l++){
			dist[i][j][k][l] = d;
			dkst[i][j][0] = dkst[i][j][1] = INF;
			light[i][j] = 0;
		    }
	for(int i = 0;i  < ns;i++){
	    scanf(" %c-%d %d", &xa, &ya, &k);
	    xa -= 'a';
	    light[xa][ya] = k;
	}
	cin >> nc;
	for(int i = 0;i < nc;i++){
	    scanf(" %c-%d %c-%d", &xa, &ya, &xb, &yb);
	    xa -= 'a';
	    xb -= 'a';
	    dist[xb][yb][xa][ya] = dist[xa][ya][xb][yb] = INF;
	}
	cin >> nj;
	for(int i = 0;i < nj;i++){
	    scanf(" %c-%d %c-%d %d", &xa, &ya, &xb, &yb, &k);
	    xa -= 'a';
	    xb -= 'a';
	    dist[xa][ya][xb][yb] += k;
	    dist[xb][yb][xa][ya] = dist[xa][ya][xb][yb];
	}
	scanf(" %c-%d %c-%d", &xa, &ya, &xb, &yb);
	xa -= 'a';
	xb -= 'a';
	dijkstra(P(xa, ya));
	cout << min(dkst[xb][yb][0], dkst[xb][yb][1]) << endl;
    }
    return 0;
}
