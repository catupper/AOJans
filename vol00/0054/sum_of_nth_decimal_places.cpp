#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a, b, n;
    while(cin >> a >> b >> n){
	a %= b;
	a *= 10;
	int res = 0;
	while(n--){
	    res += a / b;
	    a %= b;
	    a *= 10;
	}
	cout << res << endl;
    }
    return 0;
}
