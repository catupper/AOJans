#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[5250], n, m, a, b;
vector<int> edge[5250], ans;
bool used[5250];

void topo(int x){
    if(used[x])return;
    used[x] = true;
    for(int i = 0;i < edge[x].size();i++){
	topo(edge[x][i]);
    }
    cout << x << endl;
    ans.push_back(x);
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
	cin >> a >> b;
	edge[b].push_back(a);
    }

    for(int i = 1;i < n;i++){
	topo(i);
    }
    bool original = true;
    for(int i = 0;i < n - 1;i++){
	int tmp = ans[i + 1], child = ans[i];
	if(find(edge[tmp].begin(), edge[tmp].end(), child) == edge[tmp].end()){
	    original = false;
	    break;
	}
    }
    if(original)cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
