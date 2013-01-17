#include<cstdio>
#include<map>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
#define INF (1 << 30)

int n, m, a, b, c, d, x1, x2, y1, y2;
int cost[100][100], dist[100];

int dijkstra(int start, int goal){
    fill(dist, dist + n, INF);
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P> > PQ;
    PQ.push(P(0, start));
    while(!PQ.empty()){
	P tmp = PQ.top();PQ.pop();
	int from = tmp.second;
	if(dist[from] < tmp.first)continue;
	dist[from] = tmp.first;
	for(int i = 0;i < n;i++){
	    if(cost[from][i] == INF)continue;
	    if(cost[from][i] + dist[from] <= dist[i])PQ.push(P(dist[from] + cost[from][i], i));
	}
    }
    return dist[goal];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
	    cost[i][j] = INF;
    for(int i = 0;i < m;i++){
	scanf("%d,%d,%d,%d", &a, &b, &c, &d);
	a--;b--;
	cost[a][b] = c;
	cost[b][a] = d;
    }
    scanf("%d,%d,%d,%d", &x1, &x2, &y1, &y2);
    x1--;x2--;
    int res = 0;
    res += dijkstra(x1, x2);
    res += dijkstra(x2, x1);
    printf("%d\n", y1 - y2 - res);
    return 0;
}
