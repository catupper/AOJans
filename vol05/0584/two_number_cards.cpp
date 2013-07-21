#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long>res, num;
int n, tmp;
long long comb(long long a, long long b){
    long long tb = b;
    while(tb){
	a *= 10;
	tb /= 10;
    }
    return a + b;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> tmp;
	num.push_back(tmp);
    }
    for(int i = n;i < 4;i++){
	num.push_back(999999);
    }
    sort(num.begin(), num.end());
    for(int i = 0;i < 4;i++){
	for(int j = 0;j < 4;j++){
	    if(i == j)continue;
	    res.push_back(comb(num[i], num[j]));
	}
    }
    sort(res.begin(), res.end());
    cout << res[2] << endl;
    return 0;
}
