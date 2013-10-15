#include<iostream>
#include<algorithm>

using namespace std;
#define EPS (1e-10)
#define ABS(x) ((x) < 0?-(x):(x))

int main(){
    double xa, ya, xb, yb, xc, yc, xd, yd;
    while(cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd){
	if(ABS((xa - xb) * (xc - xd) + (ya - yb) * (yc- yd)) < EPS)cout << "YES" <<endl;
	else
	    cout << "NO" << endl;
    }
    return 0;
}
