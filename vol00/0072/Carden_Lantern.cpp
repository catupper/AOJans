#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> T;
int u[105];

int p(int x){
    if(u[x] == x)return x;
    return u[x] = p(u[x]);
}

void unin(int x, int y){
    x = p(x);
    y = p(y);
    u[x] = y;
}

int main(){
    int n, m, a, b, w;
    while(cin >> n, n){
	cin >> m;
	int res = 0;
	priority_queue<T, vector<T>, greater<T> > pq;
	for(int i = 0;i < m;i++){
	    scanf("%d,%d,%d", &a, &b, &w);
	    w/=100;w--;
	    pq.push(T(w, P(a, b)));
	}
	for(int i = 0;i <= n;i++)u[i] = i;
	while(!pq.empty()){
	    T tmp = pq.top();pq.pop();
	    int a = tmp.second.first, b = tmp.second.second;
	    if(p(a) == p(b))continue;
	    unin(a, b);
	    res += tmp.first;
	}
	cout << res << endl;
    }
    return 0;
}
