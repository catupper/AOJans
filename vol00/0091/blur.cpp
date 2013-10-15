#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int a[10][10];
int rem, n;
bool big(int x, int y, int r){
    bool res = true;
    if(x - 2 < 0 || x + 2 >= 10 || y - 2 < 0 || y + 2 >= 10)return false;
    for(int i = x - 2;i <= x + 2;i++)
	for(int j = y - 2;j <= y + 2;j++)
	    if(abs(x - i) + abs(y - j) <= 2){		
		a[i][j] += r;
		rem += r;
		if(a[i][j] < 0)res = false;
	    }
    if(!res)big(x, y, -r);
    return res;
}

bool small(int x, int y, int r){
    bool res = true;
    if(x - 1 < 0 || x + 1 >= 10 || y - 1 < 0 || y + 1 >= 10)return false;
    for(int i = x - 1;i <= x + 1;i++)
	for(int j = y - 1;j <= y + 1;j++)
	    if(abs(x - i) + abs(y - j) <= 1){
		a[i][j] += r;
		rem += r;
		if(a[i][j] < 0)res = false;
	    }
    if(!res)small(x, y, -r);
    return res;
}

bool middle(int x, int y, int r){
    bool res = true;
    if(x - 1 < 0 || x + 1 >= 10 || y - 1 < 0 || y + 1 >= 10)return false;
    for(int i = x - 1;i <= x + 1;i++)
	for(int j = y - 1;j <= y + 1;j++){
	    a[i][j] += r;
	    rem += r;
	    if(a[i][j] < 0)res = false;
	}
    if(!res)middle(x, y, -r);
    return res;
}

typedef pair<int, int> P;
typedef pair<P, int> T;

vector<T> ans;

bool solve(int n,int p = 0, int q = 0){
    if(rem > 13 * n)return false;
    for(int i = p;i < 10;i++){
	for(int j = 0;j < 10;j++){
	    if(i - 2 >= 0 && j - 2 >= 0 && a[i - 2][j - 2])return false;
	    if(a[i][j] == 0)continue;
	    if(big(i, j, -1)){
		ans.push_back(T(P(i, j), 3));
		if(solve(n - 1, i, j))return true;
		ans.pop_back();
		big(i, j, 1);
	    }
	    if(middle(i, j, -1)){
		ans.push_back(T(P(i, j), 2));
		if(solve(n - 1, i, j))return true;
		ans.pop_back();
		middle(i, j, 1);
	    }
	    if(small(i, j, -1)){
		ans.push_back(T(P(i, j), 1));
		if(solve(n - 1, i, j))return true;
		ans.pop_back();
		small(i, j, 1);
	    }
	}
    }
    return (n == 0);
}

int main(){
    cin >> n;
    for(int i = 0;i < 10;i++)
	for(int j = 0;j < 10;j++){
	    cin >> a[i][j];
	    rem += a[i][j];
	}
    
    solve(n);
    for(int i = 0;i < ans.size();i++){
	cout << ans[i].first.second << " "<< ans[i].first.first << " "<<ans[i].second << endl;
    }
    return 0;
}
