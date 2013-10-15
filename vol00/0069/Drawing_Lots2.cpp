#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int m, d, g, n;
bool change[105][105];
string r;
bool goal(){
    int now = m - 1;
    for(int i = 0;i < d;i++){
	if(change[i][now - 1]){
	    now--;
	}
	else if(change[i][now]){
	    now++;
	}
    }
    return now == g - 1;
}

int main(){
    while(cin >> n, n){
	cin >> m >> g >> d;
	for(int i = 0;i < d;i++){
	    cin >> r;
	    for(int j = 0;j < n - 1;j++){
		change[i][j] = r[j] == '1';
		change[i][j + 1] = false;
	    }
	}
	if(goal()){
	    cout << 0 << endl;
	    continue;
	}
	bool ok = false;
	for(int i = 0;i < d && !ok;i++){
	    for(int j = 0;j < n - 1 && !ok;j++){
		if((j == 0 || !change[i][j - 1]) && !change[i][j + 1] && !change[i][j]){
		    change[i][j] = true;
		    if(goal()){
			ok = true;
			cout << i + 1 << " " << j + 1 << endl;
		    }
		    change[i][j] = false;
		}
	    }
	}
	if(!ok){
	    cout << 1 << endl;
	}
    }
    return 0;
}
