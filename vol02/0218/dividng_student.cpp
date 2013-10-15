#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, pm, pe, pj;
    while(cin >> n, n){
	while(n--){
	    cin >> pm >> pe >> pj;
	    if(pm == 100 || pe == 100 || pj == 100){
		cout << "A" << endl;
		continue;
	    }
	    if(pm + pe >= 180){
		cout << "A" << endl;
		continue;
	    }
	    if(pm + pe + pj >= 240){
		cout << "A" << endl;
		continue;
	    }
	    if(pm + pe + pj >= 210){
		cout << "B" << endl;
		continue;
	    }
	    if(pm + pe + pj >= 150 && (pm >= 80 || pe >= 80)){
		cout << "B" << endl;
		continue;
	    }
	    cout << "C" << endl;
	}
    }
    return 0;
}
