#include<iostream>
#include<algorithm>
#define max(a, b) (a>b?a:b)
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;
    int res = m;
    for(int i = 0;i < n;i++){
	cin >> a >> b;
	m += a-b;
	res = max(res, m);
	if(m < 0){cout << 0<< endl;return 0;}
    }
    cout << res << endl;
    return 0;
}
