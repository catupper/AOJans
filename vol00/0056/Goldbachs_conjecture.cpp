#include<iostream>
#include<algorithm>
using namespace std;

int p[105000];

int main(){
    int n;
    p[0] = p[1] = 1;
    for(int i = 2;i * i <= 105000;i++){
	if(p[i])continue;
	for(int j = i * i;j <= 105000;j += i){
	    p[j] = 1;
	}
    }
    while(cin >> n, n){
	int res = 0;
	for(int i = 0;i <= n / 2;i++){
	    if(p[i] == 0  && p[n - i] == 0)res++;
	}
	cout << res << endl;
    }
    return 0;
}
