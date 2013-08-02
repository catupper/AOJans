#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> str;
string conj[15][15];
int n;
bool used[15];
string answer(int x, int p){
    if(p == 0)return str[x];
    int res = (1 << 20);
    string ans;
    for(int i = 0;i < n;i++){
	if(used[i])continue;
	used[i] = true;
	string tmp = answer(i, p - 1);
	used[i] = false;
	if(x != -1)tmp = conj[x][i] + tmp;
	int p = tmp.size();
	if(p > res || p == res && ans < tmp)continue;	  
	res = p;
	ans = tmp;
    }
    return ans;
}

string conjection(string a, string b){
    string t = "";
    for(int i = 0;i < a.size();i++){
	if(i + b.size() <= a.size()){
	    t += a[i];
	    continue;
	}
	bool res = true;
	for(int j = i;j < a.size();j++){
	    if(a[j] != b[j - i]){
		res = false;break;
	    }
	}
	if(res)return t;
	t += a[i];
    }
    return t;
}

bool in(string a, string b){
    if(b.size() > a.size())return false;
    for(int i = 0;i < a.size();i++){
	if(i + b.size() > a.size())return false;
	bool t = true;
	for(int j = i;j < a.size();j++){
	    if(j - i == b.size())break;
	    if(a[j] != b[j - i]){
		t = false;
		break;
	    }
	}
	if(t)return t;
    }
    return false;
}

int main(){
    while(true){
	cin >> n;
	str.clear();
	if(n == 0)return 0;
	for(int i = 0;i < 15;i++)
	    for(int j = 0;j < 15;j++)
		conj[i][j] = "";


	for(int i = 0;i < n;i++){
	    string tmp;
	    cin >> tmp;
	    str.push_back(tmp);
	}
	for(int i = 0;i < n;i++){
	    for(int j = 0;j < n;j++){
		if(i == j)continue;
		if(in(str[i], str[j])){
		    str[j] = str[i];
		}
	    }
	}
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	n = str.size();
	for(int i = 0;i < n;i++){
	    for(int j = 0;j < n;j++){
		if(i == j)continue;
		conj[i][j] = conjection(str[i], str[j]);
	    }
	}
	cout << answer(-1, n) << endl;
    }
    return 0;
}
