#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, t, a, b;
    while(cin >> t, t){
	cin >> n;
	int sum = 0;
	for(int i = 0;i < n;i++){
	    cin >> a >> b;
	    sum += b - a;
	}
	if(sum >= t){
	    cout << "OK" << endl;
	}
	else{
	    cout << t - sum << endl;
	}
    }
    return 0;
}
