#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define INF (1 << 30)
typedef pair<int, int> P;
int dist[1050];
vector<P> edge[1050], two;
int n, m, a, b, c;
void dijkstra(int start){
    fill(dist, dist + 1050, INF);
    dist[start] = 0;
    priority_queue<P> pq;
    pq.push(P(0, start));
    while(!pq.empty()){
	P tmp = pq.top();pq.pop();
	int from = tmp.second, r = tmp.first;
	if(dist[from] < r)continue;
	for(int i = 0;i < edge[from].size();i++){
	    int to = edge[from][i].first, d = edge[from][i].second;
	    if(dist[to] <= dist[from] + d)continue;
	    dist[to] = dist[from] + d;
	    pq.push(P(dist[to], to));
	}
    }
}

int main(){
    while(cin >> n >> m, n|m){
	for(int i = 1;i <= n + n;i++)edge[i].clear();
	two.clear();
	for(int i = 0;i < m;i++){
	    cin >> a >> b >> c;
	    edge[a].push_back(P(b, c));
	    edge[b].push_back(P(a, c));
	    edge[a + n].push_back(P(b + n, c));
	    edge[b + n].push_back(P(a + n, c));
	}
	for(int i = 1;i <= n;i++){
	    for(int j = 0;j < edge[i].size();j++){
		for(int k = j + 1;k < edge[i].size();k++){
		    two.push_back(P(edge[i][j].first, edge[i][k].first));
		}
	    }
	}
	for(int i = 0;i < two.size();i++){
	    a = two[i].first, b = two[i].second;
	    edge[a].push_back(P(b + n, 0));
	    edge[b].push_back(P(a + n, 0));
	}
	edge[n].push_back(P(n + n, 0));
	dijkstra(1);

	cout << dist[n + n] << endl;
    }
    return 0;
}
