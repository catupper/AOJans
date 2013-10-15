#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

char r[10500];
int main(){
    int p = 0;
    int res = 0;
    while(~(r[p]=getchar())){
	if('0' <= r[p] && r[p] <= '9'){
	    p++;
	    r[p + 1] = 0;
	    continue;
	}
	else{
	    int t;
	    if(1==sscanf(r, "%d", &t))res += t;
	    p = 0;
	    r[p + 1] = 0;
	}
    }
    int t;
    if(1==sscanf(r, "%d", &t))res += t;
    cout << res << endl;
}
