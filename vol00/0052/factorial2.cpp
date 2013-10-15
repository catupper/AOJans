#include<iostream>
#include<algorithm>

using namespace std;

long long n;

int main(){
    while(cin >> n, n){
	long long a = 5;
	long long res = 0;
	while(a <= n){
	    res += n / a;
	    a *= 5;
	}
	cout << res << endl;
    }
    return 0;
}
