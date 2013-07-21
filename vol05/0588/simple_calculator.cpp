#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int p = 0, q, res = -10;
    char x;
    while(++p){
	if(p & 1){
	    if(x != '=')
		cin >> q;
	    if(res == -10)res = q;
	    else{
		switch(x){
		case '+':
		    res += q;
		    break;
		case '-':
		    res -= q;
		    break;
		case '*':
		    res *= q;
		    break;
		case '/':
		    res /= q;
		    break;
		case '=':
		    cout << res << endl;
		    return 0;
		}
	    }
	}
	else{
	    cin >> x;
	}
    }
}
