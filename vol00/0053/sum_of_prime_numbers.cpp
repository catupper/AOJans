#include<iostream>
#include<algorithm>

using namespace std;

int p[105000];
long long s[105000];

int main(){
    p[0] = p[1] = 1;
    for(int i = 2;i * i <= 105000;i++){
	if(p[i])continue;

	for(int j = i * i;j < 105000;j+=i){
	    p[j] = 1;
	}
    }
    int r = 1;
    for(int j = 0;j <= 105000;j++){
	if(p[j] == 0){
	    s[r] = s[r - 1] + j;
	    r++;
	}
    }
    int n;
    while(cin >> n, n){
	cout << s[n] << endl;
    }
    return 0;
}
