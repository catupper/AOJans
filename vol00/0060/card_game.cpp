#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int c1, c2, c3;
    while(cin >> c1 >> c2 >> c3){
	int p = 20 - c1 - c2, res = 0;
	for(int i = 1;i <= 10;i++){
	    if(i == c1 || i == c2 || i == c3)continue;
	    if(i <= p)res++;
	}
	if(p > 3)cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}
