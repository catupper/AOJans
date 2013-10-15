#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int u[105];

int p(int x){
    if(x == u[x])return x;
    return u[x] = p(u[x]);
}

void unin(int a, int b){
    a = p(a);
    b = p(b);
    u[a] = b;
}

int main(){
    int n, in[105], out[105];
    string str;
    while(cin >> n, n){
	for(int i = 0;i < 26;i++){
	    in[i] = out[i] = 0;
	    u[i] = i;
	}
	int c;
	for(int i = 0;i < n;i++){
	    cin >> str;
	    c = str[0];
	    in[str[0] - 'a']++;
	    out[str[str.size() - 1] - 'a']++;
	    unin(str[0] - 'a', str[str.size() - 1] - 'a');
	}
	bool ok = true;
	for(int i = 0;i < 26;i++){
	    if(in[i] != out[i])ok = false;
	    if(in[i] && p(c - 'a') != p(i))ok = false;
	}
	if(ok)cout << "OK" << endl;
	else cout << "NG" << endl;
    }
    return 0;
}
