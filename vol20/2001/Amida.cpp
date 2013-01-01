#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> L;
int main(){
    int n, m, a;
    L l[1050];
    while(true){
	cin >> n >> m >> a;
	if(n == 0 && m == 0 && a == 0)return 0;
	for(int i = 0;i < m;i++){
	    cin >> l[i].first >> l[i].second.first >> l[i].second.second;
	}
	sort(l, l + m, greater<L>());
	for(int i = 0;i < m;i++){
	    P tmp = l[i].second;
	    if(tmp.first == a)a = tmp.second;
	    else if(tmp.second == a)a = tmp.first;
	}
	cout << a << endl;
    }
}
