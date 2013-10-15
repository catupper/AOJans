#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define INF (1LL << 60)
typedef pair<long long, long long> P;

vector<P> valid_edge;
long long adist[105000], bdist[105000];
vector<P> edge[105000];
long long come[105000];
void dijkstra(long long start, long long *dist){
    fill(dist, dist + 103000, INF);
    priority_queue<P, vector<P>, greater<P> > pq;
    dist[start] = 0;
    pq.push(P(0, start));
    while(!pq.empty()){
	P tmp = pq.top();pq.pop();
	long long from = tmp.second, d = tmp.first;
	if(dist[from] < d)continue;
	for(long long i = 0;i < edge[from].size();i++){
	    long long to = edge[from][i].first, r = edge[from][i].second;
	    if(dist[from] + r >= dist[to])continue;
	    dist[to] = dist[from] + r;
	    pq.push(P(dist[to], to));
	}
    }
}

bool comp(const int &a, const int &b){
    return adist[a] < adist[b];
}

int main(){
    long long s, r, a, b, q, u[210000], v[210000], w[210000];
    cin >> s >> r;
    for(long long i = 0;i < r;i++){
	cin >> u[i] >> v[i] >> w[i];
	edge[u[i]].push_back(P(v[i], w[i]));
	edge[v[i]].push_back(P(u[i], w[i]));
    }
    cin >> a >> b >> q;
    dijkstra(a, adist);
    dijkstra(b, bdist);
    long long c[64], d[64];
    long long dp[105000];
    long long topo[105000];
    for(int i = 0;i < 105000;i++)topo[i] = i;
    sort(topo, topo + s, comp);
    for(long long i = 0;i < q;i += 50){
	fill(dp, dp + 105000, 0);
	for(long long j = 0;j < 50 && i + j < q;j++){
	    cin >> c[j] >> d[j];
	    dp[c[j]] |= (1ULL << j);
	}
	for(int j = 0;j < s;j++){
	    int p = topo[j];
	    if(adist[p] + bdist[p] != adist[b])continue;
	    for(int k = 0;k < edge[p].size();k++){
		int to = edge[p][k].first, d = edge[p][k].second;
		if(adist[to] + bdist[to] == adist[b] &&
		   adist[to] == adist[p] + d)
		    dp[to] |= dp[p];
	    }
	}
	for(long long j = 0;j < 50 && i + j < q;j++){
	    if(dp[d[j]] & (1ULL << j))cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
    }
    return 0;
}
