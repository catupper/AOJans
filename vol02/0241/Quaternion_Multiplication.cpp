#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a1, ai, aj, ak, b1, bi, bj, bk, n;
    while(cin >> n, n){
	for(int i = 0;i < n;i++){
	    cin >> a1 >> ai >> aj >> ak >> b1 >> bi >> bj >> bk;
	    cout << a1 * b1 - ai * bi - aj * bj - ak * bk << " ";
	    cout << a1 * bi + ai * b1 + aj * bk - ak * bj << " ";
	    cout << a1 * bj + aj * b1 + ak * bi - ai * bk << " ";
	    cout << ak * b1 - aj * bi + ai * bj + a1 * bk << endl;
	}
    }
    return 0;
}
