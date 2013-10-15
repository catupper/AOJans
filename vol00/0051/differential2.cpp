#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

int solve(string str){
    char x[9], y[9];
    x[8] = y[8] = 0;
    string rev;
    for(int i = 0;i < 8;i++)x[i] = str[i];
    sort(x, x + 8);
    for(int i = 0;i < 8;i++)y[i] = x[7 - i];
    int a, b;
    sscanf(x, "%d", &a);
    sscanf(y, "%d", &b);
    return abs(a- b);
}

int main(){
    int n;
    string str;
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> str;
	cout << solve(str) << endl;
    }
    return 0;
}
