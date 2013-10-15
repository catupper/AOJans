#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
int xs[] = {0, 1, 0, -1}, ys[] = {1, 0, -1, 0};
bool m[20][20];
void dfs(int x, int y){
    for(int i = 0;i < 4;i++){
	int tx = x + xs[i], ty = y + ys[i];
	if(tx < 0 || tx >= 12 || ty < 0 || ty >= 12)continue;
	if(m[tx][ty]){
	    m[tx][ty] = false;
	    dfs(tx, ty);
	}

    }
}

int main(){
    while(true){
	int res = 0;
	for(int i = 0;i < 12;i++){
	    if(cin >> str){
		for(int j = 0;j < str.size();j++){
		    m[i][j] = str[j] == '1';
		}
	    }
	    else return 0;
	}
	for(int i = 0;i < 12;i++){
	    for(int j = 0;j < 12;j++){
		if(m[i][j]){
		    res++;
		    dfs(i, j);
		}		
	    }
	}
	cout << res << endl;
    }
}
