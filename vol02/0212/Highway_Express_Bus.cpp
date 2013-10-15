#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> T;
#define INF (1 << 30)
vector<P> edge[1050];
int dist[105][15];

void dijkstra(int s, int c){
    for(int i = 0;i < 15;i++)
	for(int j = 0;j < 105;j++)
	    dist[j][i] = INF;
    dist[s][c] = 0;
    priority_queue<T> pq;
    pq.push(T(0, P(s, c)));
    while(!pq.empty()){
	T tmp = pq.top();pq.pop();
	int from = tmp.second.first, tc = tmp.second.second;
	if(dist[from][tc] < tmp.first)continue;
	for(int i = 0;i < edge[from].size();i++){
	    int to = edge[from][i].first, d = edge[from][i].second;
	    if(dist[to][tc] > dist[from][tc] + d){
		dist[to][tc] = dist[from][tc] + d;
		pq.push(T(dist[to][tc], P(to, tc)));
	    }
	    if(tc > 0 && dist[to][tc - 1] > dist[from][tc] + d / 2){
		dist[to][tc - 1] = dist[from][tc] + d / 2;
		pq.push(T(dist[to][tc - 1], P(to, tc - 1)));
	    }
	}
    }
}

int main(){
    int c, n, m, s, d, a , b, f;
    while(cin >> c >> n >> m >> s >> d, d){
	for(int i = 1;i <= n;i++){
	    edge[i].clear();
	    edge[i].push_back(P(i, 0));
	}
	for(int i = 0;i < m;i++){
	    cin >> a >> b >> f;
	    edge[a].push_back(P(b, f));
	    edge[b].push_back(P(a, f));
	}
	dijkstra(s, c);
	cout << dist[d][0] << endl;
    }
    return 0;
}
