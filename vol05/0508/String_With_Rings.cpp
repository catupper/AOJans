#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool used[105];
vector<int> edge[105];
int n, a, b;

int dfs(int x){
    if(edge[x].empty())return 0;
    if(used[x])return 0;
    int res = 0;
    used[x] = true;
    for(int i = 0;i < edge[x].size();i++){
	res = max(res, dfs(edge[x][i]));
    }
    used[x] = false;
    return res + 1;
}

int main(){
    while(true){
	cin >> n;
	if(n == 0)return 0;
	for(int i = 0;i < 100;i++){
	    edge[i].clear();
	}
	for(int i = 0;i < n;i++){
	    cin >> a >> b;
	    a--,b--;
	    edge[a].push_back(b);
	    edge[b].push_back(a);
	}
	int res = 0;
	for(int i = 0;i < 100;i++){
	    res = max(res, dfs(i));
	}
	cout << res << endl;
    }
}
