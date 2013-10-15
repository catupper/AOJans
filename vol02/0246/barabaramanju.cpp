#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define INF (1 << 30)
typedef pair<vector<int>, int> P;
vector< vector<int> > tens;
map<pair<vector<int>, int>, int > table;
vector<int> tmp(10);
int n;
int num[10];
void tendfs(int num, int now, int sum = 0, int cnt = 0){
    if(sum == 10){
	if(cnt > 2)tens.push_back(tmp);
	return;
    }
    if(num > 10 - sum)return;
    tmp[num]++;
    tendfs(num, now, sum + num, cnt + 1);
    tmp[num]--;
    tendfs(num + 1, now, sum, cnt);
}

int dfs(int n){
    if(n == tens.size())return 0;

    if(table.find(P(tmp, n)) != table.end())return table[P(tmp, n)];
    int res = dfs(n + 1);
    int ok = 1;
    for(int i = 1;i <= 9;i++){
	num[i] -= tens[n][i];
	if(num[i] < 0)ok = 0;
    }
    if(ok)res = max(dfs(n) + 1, res);
    for(int i = 1;i <= 9;i++){
	num[i] += tens[n][i];
    }
    table[P(tmp, n)] = res;
    return res;
}
int x;
int main(){
    tendfs(1, 1);
    while(cin >> n, n){
	while(table.size())table.erase(table.begin());
	int ans = 0;
	fill(num, num + 10, 0);
	for(int i = 0;i < n;i++)cin >> x,num[x]++;
	for(int i = 1;i < 5;i++){
	    int t = min(num[i], num[10 - i]);
	    num[i] -= t;
	    num[10 - i] -= t;
	    ans += t;
	}
	ans += num[5] / 2;
	num[5] %= 2;
	cout << ans + dfs(0) << endl;
    }
}
