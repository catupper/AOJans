#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int rev(int x){
    int res = 0;
    while(x){
	res += x%10;
	x/=10;
	res*=10;
    }
    return res / 10;
}

int prime(int x){
    for(int i = 2;i * i <= x;i++){
	if(x % i == 0)return 0;
    }
    return 1;
}

string tim(string a, int b){
    string res = "";
    while(b--)res+=a;
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    if(b < 0){
	if(a == 1)cout << 11 << endl;
	else cout << tim("9", (a+a)) << endl;
	return 0;
    }
    int p = 1;
    for(int i = 0;i < a;i++)p *= 10;
    p--;
    int l = (p + 1) / 10;
    for(int i = p;i >= l;i--){
	int x = i * l * 100 + b * l * 10 + rev(i);
	if(prime(x)){
	    cout << x << endl;
	    return 0;
	}
    }
    cout <<tim("9",a) << b << tim("9",a) << endl;
    return 0;
}
