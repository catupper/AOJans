#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<char, int> dict;
int main(){
    dict['I'] = 1;
    dict['V'] = 5;
    dict['X'] = 10;
    dict['L'] = 50;
    dict['C'] = 100;
    dict['D'] = 500;
    dict['M'] = 1000;
    string str;
	    
    while(cin >> str){
	int res = 0;
	char now = str[0];
	int cnt = 1;
	for(int i = 1;i < str.size();i++){
	    if(str[i] == now)cnt++;
	    else{
		if(dict[str[i]] > dict[now])res -= cnt * dict[now];
		else res += cnt * dict[now];
		now = str[i];
		cnt = 1;
	    }
	}
	res += cnt * dict[now];
	cout << res << endl;
    }
    return 0;
}
