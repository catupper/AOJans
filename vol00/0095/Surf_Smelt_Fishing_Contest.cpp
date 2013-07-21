#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    int ra = 1 << 29;
    int rb = -100;
    for(int i = 0;i < n;i++){
	cin >> a >> b;
	if(rb < b || rb == b && ra > a){
	    ra = a;
	    rb = b;
	}
    }
    cout << ra << " " << rb << endl;
    return 0;
}
