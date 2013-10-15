#include<iostream>
#include<algorithm>

using namespace std;
int a, b, cnt[10];
int main(){
    while(cin >> a >> b, a | b){
	fill(cnt, cnt + 10, 0);
	int hit = 0, blow = 0;
	for(int i = 0;i < 4;i++){
	    cnt[a%10]++;
	    cnt[b%10]++;
	    if(cnt[a%10] == 2)blow++;
	    if(cnt[b%10] == 2)blow++;
	    if(a%10 == b%10)hit++,blow--;
	    a/=10,b/=10;
	}
	cout << hit << " " << blow - hit << endl;
    }
    return 0;
}
