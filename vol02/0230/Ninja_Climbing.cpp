#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> T;
#define INF (1 << 30)
int n, dist[2][210], window[2][210];
vector<T> edge[2][210];
bool come[2][210];
int main(){
    while(cin >> n, n){
	for(int j = 0;j < 2;j++){
	    for(int i = 0;i < n;i++){
		cin >> window[j][i];
		dist[j][i] = INF;
		come[j][i] = false;
		edge[j][i].clear();
	    }
	}
	for(int j = 0;j < 2;j++){
	    for(int i = 0;i < n;i++){
		if(window[j][i] == 0 ||(window[j][i] == 1 && window[j][i + 1] != 1)){
		    for(int k = 0;k <= 2;k++){
			edge[j][i].push_back(T(1, P(!j, i + k)));
		    }
		}
		if(window[j][i + 1] == 1 && window[j][i] == 1){
		    edge[j][i].push_back(T(0, P(j, i + 1)));
		}
		if(window[j][i] == 2){
		    edge[j][i].push_back(T(0, P(j, i - 1)));
		}
	    }
	}
	priority_queue<T, vector<T>, greater<T> > pq;
	pq.push(T(0, P(0, 0)));
	pq.push(T(0, P(1, 0)));
	dist[0][0] = dist[1][0] = 0;
	while(!pq.empty()){
	    T tmp = pq.top();pq.pop();
	    int d = tmp.first, x = tmp.second.first, y = tmp.second.second;
	    come[x][y] = true;
	    if(dist[x][y] < d)continue;
	    for(int i = 0;i < edge[x][y].size();i++){
		P to = edge[x][y][i].second;
		int r = edge[x][y][i].first, tx = to.first, ty = to.second;
		if(dist[tx][ty] <= d + r)continue;
		dist[tx][ty] = d + r;
		pq.push(T(dist[tx][ty], to));
	    }
	}
	int res = min((window[0][n - 1]==2)?INF:dist[0][n - 1], (window[1][n - 1]==2)?INF:dist[1][n - 1]);
	if(res == INF)cout << "NA" << endl;
	else cout << res << endl;
    }
    return 0;
}
