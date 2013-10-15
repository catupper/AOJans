#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n, n != -1){
	int res = 1150;
	n -= 10;
	res += 125 * max(0, min(10, n));
	n -= 10;
	res += 140 * max(0, min(10, n));
	n -= 10;
	res += 160 * max(0, n);
	cout << 4280 - res << endl;
    }
    return 0;
}
