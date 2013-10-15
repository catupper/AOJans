#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    double n;
    while(cin >> n, n >= 0){
	n *= 1 << 4;
	if(n != (int)n || n >= (1 << 13)){
	    cout << "NA" << endl;
	    continue;
	}
	int l = (int)n >> 4, r = n - (l << 4);
	for(int i = 7;i >= 0;i--){
	    cout << ((l >> i) & 1);
	}
	cout << '.';
	for(int i = 3;i >= 0;i--){
	    cout << ((r >> i) & 1);
	}
	cout << endl;
    }
}
