#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool pal(string a){
    string p = "";
    for(int i = a.size() - 1;i >= 0;i--){
	p += a[i];
    }
    return p == a;
}

int main(){
    string str;
    int res = 0;
    while(cin >> str){
	if(pal(str))res++;
    }
    cout << res << endl;
    return 0;
}
