#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

typedef pair<double, string> P;

double exp(int j, double a, double b){
    switch(j){
    case 0:
	return a + b;
    case 1:
	return a - b;
    case 2:
	return b - a;
    case 3:
	return a * b;
    }
}

string comb(int j, string a, string b){
    switch(j){
    case 0:
	return "(" + a + "+" + b + ")";
    case 1:
	return "(" + a + "-" + b + ")";
    case 2:
	return "(" + b + "-" + a + ")";
    case 3:
	return "(" + a + "*" + b + ")";
    }
}

vector<P> solve(vector<double> x){
    vector<P> res;
    if(x.size() == 1){
	string r = "";r += '0' + x[0];
	res.push_back(P(x[0], r));
	return res;    
    }
    for(int i = 0;i < x.size() - 1;i++){
	vector<P> a = solve(vector<double>(x.begin(), x.begin() + i + 1));
	vector<P> b = solve(vector<double>(x.begin() + i + 1, x.end()));

	for(int i = 0;i < a.size();i++){
	    for(int j = 0;j < b.size();j++){
		for(int k = 0;k < 4;k++){
		    double td = exp(k, a[i].first, b[j].first);
		    string rem = comb(k, a[i].second, b[j].second);
		    res.push_back(P(td, rem));
		}
	    }
	}
    }
}

int main(){
    vector<double> x(4);
    while(cin >> x[0] >> x[1] >> x[2] >> x[3]){
	if(x[0] == 0)return 0;
	vector<P> ans;
	sort(x.begin(), x.end());
	do{
	    vector<P> tmp = solve(x);
	    ans.insert(ans.end(), tmp.begin(), tmp.end());
	}while(next_permutation(x.begin(), x.end()));
	string res = "0";
	for(int i = 0;i < ans.size();i++){
	    if(fabs(ans[i].first - 10) < 1e-10){
		res = ans[i].second;break;
	    }
	}
	cout << res << endl;
    }
}
