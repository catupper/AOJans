#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[1050], q[1050], r[1050], c[1050], n;
int pp, qq, rr, cc, ind[1050];

int main(){
    while(cin >> n, n){
	for(int i = 0;i < n;i++){
	    cin >> ind[i] >> p[i] >> q[i] >> r[i];
	    c[i] = 4 * p[i] + 9 * q[i] + 4 * r[i];
	}
	cin >> pp >> qq >> rr >> cc;
	int ok = 0;
	for(int i = 0;i < n;i++){
	    if(p[i] <= pp && q[i] <= qq && r[i] <= rr && c[i] <= cc){
		cout << ind[i] << endl;
		ok = 1;
	    }
	}
	if(ok == 0)cout << "NA" << endl;
    }
    return 0;
}
