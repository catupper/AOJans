#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

vector<string> ans;

int main(){
    string res = "";
    char c;
    while(~(c = getchar())){
	if(c == ',' || c == ' ' || c == '.'){
	    if(res.size() >= 3 && res.size() <= 6)
		ans.push_back(res);	    
	    res = "";
	}
	else{
	    res += c;
	}
    }
    for(int i = 0;i < ans.size();i++){
	cout << ans[i];
	if(i != ans.size()-1)cout << " ";
    }
    cout << endl;
    return 0;
}
