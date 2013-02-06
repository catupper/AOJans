#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, num[4][222];
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> num[0][i] >> num[1][i] >> num[2][i];
    }
    for(int i = 0;i < n;i++){
	int res = 0;
	for(int j = 0;j < 3;j++){
	    res += num[j][i];
	    for(int k = 0;k < n;k++){
		if(i == k)continue;
		if(num[j][i] == num[j][k]){
		    res -= num[j][i];
		    break;
		}
	    }
	}
	cout << res << endl;
    }
    return 0;
}
