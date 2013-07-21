#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
	if(a == -1 && b == -1 && c == -1)return 0;
	int t = 2 * 3600 - a * 3600 - b * 60 - c;
	printf("%02d:%02d:%02d\n", t/3600, (t%3600)/60, t%60);
	t *= 3;
	printf("%02d:%02d:%02d\n", t/3600, (t%3600)/60, t%60);
    }
    return 0;
    
}

