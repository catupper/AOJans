#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;

vector<P> down[105000], up[105000];
vector<int> ans[105000], res, topo;
int dp[105000];
bool come[105000];
int longest, n, m, a, b;
void toposort(int x){
    if(come[x])return;
    come[x] = true;
    for(int i = 0;i < up[x].size();i++){
	toposort(up[x][i].first);
    }
    topo.push_back(x);
}

void back(int x){
    if(come[x])return;
    come[x] = true;
    for(int i = 0;i < down[x].size();i++){
	int to = down[x][i].first;
	int tmp = down[x][i].second;
	if(dp[to] != dp[x] - 1)continue;
	ans[dp[x]].push_back(tmp);
	back(to);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
	cin >> a >> b;
	up[a].push_back(P(b, i + 1));
	down[b].push_back(P(a, i + 1));
    }
    for(int i = 1;i <= n;i++)
	toposort(i);

    for(int i = n - 1;i >= 0;i--){
	int from = topo[i];
	longest = max(longest, dp[from]);
	for(int j = 0;j < up[from].size();j++){
	    int to = up[from][j].first;
	    dp[to] = max(dp[to], dp[from] + 1);	    
	}
    }
    fill(come, come + 105000, false);
    for(int i = 1;i <= n;i++)
	if(dp[i] == longest)back(i);

    for(int i = 1;i <= n;i++){
	if(ans[i].size() == 1){
	    res.push_back(ans[i][0]);
	}
    }

    sort(res.begin(), res.end());
    for(int i = 0;i < res.size();i++)
	cout << res[i] << endl;
    if(res.size() == 0)
	cout << -1 << endl;

    return 0;
}
