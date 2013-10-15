#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;


string rev(int a, int b, string x){
    string res = "";
    for(int i = 0;i < x.size();i++){
	if(x[i] < 'a' || x[i] > 'z')res += x[i];
	else{
	    int p = x[i] - 'a';
	    p += b;
	    p *= a;	    
	    p %= 26;
	    res += 'a' + p;
	}
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    scanf("%*c");
    for(int i  = 0;i < n;i++){
	string input = "";
	char c;
	while(true){
	    c = getchar();
	    if(c == '\n' || c == EOF)break;
	    input += c;
	}
	string ans;
	for(int a = 1;a < 26;a++){
	    for(int b = 0;b < 26;b++){
		if(a % 2 == 0 || a % 13 == 0)continue;
		string o = rev(a, b, input);
		const char *orig = o.c_str();
		if(strstr(orig, "this") || strstr(orig, "that")){
		    ans = orig;
		}
	    }
	}
	cout << ans << endl;
    }
}
