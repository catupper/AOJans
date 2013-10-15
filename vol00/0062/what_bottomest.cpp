#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int solve(string str){
    int num[10];
    for(int i = 0;i < 10;i++)
	num[i] = str[i] - '0';
    for(int i = 8;i >= 0;i--){
	for(int j = 0;j <= i;j++){
	    num[j] += num[j + 1];
	    num[j] %= 10;
	}
    }
    return num[0];
}

int main(){
    string str;
    while(cin >> str){
	cout << solve(str) << endl;
    }
    return 0;
}
