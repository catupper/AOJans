#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string name, tmp;

string slice(string str, int start, int gap, int num){
    string res = "";
    for(int i = start;i < str.size() && num--;i += gap){
	res += str[i];
    }
    return res;
}

int main(){
    int res = 0, n;
    cin >> n;
    cin >> name;
    for(int i = 0;i < n;i++){
	cin >> tmp;
	bool x = true;
	for(int i = 0;i < tmp.size() && x;i++){
	    for(int j = 1;j < tmp.size();j++){
		if(name == slice(tmp, i, j, name.size())){
		    x = false;
		    res++;
		    break;
		} 
	    }
	}
    }
    cout << res << endl;
    return 0;
}
