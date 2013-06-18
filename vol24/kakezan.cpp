#include<iostream>
#include<algorithm>

using namespace std;

int table[1050000];

int solve(int x){
    if(table[x] != -2)return table[x];
    if(x < 10)return 0;
    int &res = table[x];
    res = -1;
    int p = 0;
    for(int i = 1;i <= x;i *= 10){
	p = max(p, (x / i) * (x % i));
    }
    res = solve(p);
    if(res >= 0)res++;
    return res;
}

int main(){
    int q, n;
    fill(table, table + 1050000, -2);
    cin >> q;
    while(q--){
	cin >> n;
	cout << solve(n) << endl;
    }
    return 0;
}
