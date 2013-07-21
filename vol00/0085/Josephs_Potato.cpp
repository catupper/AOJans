#include<iostream>
#include<algorithm>

using namespace std;
int num[1050];
int main(){
    int a, b;
    while(cin >> a >> b){
	if(a == 0 && b == 0)return 0;
	fill(num, num + a, 1);
	int now = 0;
	for(int i = 0;i < a - 1;i++){
	    for(int j = 1;j < b;j++){
		while(!num[(++now)%=a]);
	    }
	    num[now] = 0;
	    while(!num[(++now)%=a]);
	}
	cout << now + 1 << endl;
    }
}
