#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n, y, b, r, t;
    while(cin >> n, n){
	cin >> y;
	int ans = 0;
	double res = -1;
	for(int i = 0;i < n;i++){
	    cin >> b >> r >> t;
	    double tmp;
	    if(t == 1){
		tmp = 1.0 + y * r * 0.01;
	    }
	    else{
		tmp = pow(1.0 + r * 0.01, y);
	    }
	    if(tmp > res){
		res = tmp;
		ans = b;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
