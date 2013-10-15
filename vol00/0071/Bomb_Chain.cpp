#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    string bom[10];
    bool exp[10][10];
    int a, b;
    cin >> n;
    for(int t = 1;t <= n;t++){
	for(int i = 0;i < 8;i++){
	    cin >> bom[i];
	    for(int j = 0;j < 8;j++)exp[i][j] = false;
	}
	cin >> a >> b;
	exp[b - 1][a - 1] = true;
	for(int i = 0;i < 64;i++){
	    for(int j = 0;j < 8;j++){
		for(int k = 0;k < 8;k++){
		    if(bom[j][k] == '0')continue;
		    if(exp[j][k]){
			for(int l = 1;l <= 3;l++){
			    if(j + l < 8)exp[j + l][k] = true;
			    if(j - l >= 0)exp[j - l][k] = true;
			    if(k + l < 8)exp[j][k + l] = true;
			    if(k - l >= 0)exp[j][k - l] = true;
			}
		    }
		}
	    }
	}
	cout << "Data " << t << ":" << endl;
	for(int i = 0;i < 8;i++){
	    for(int j = 0;j < 8;j++){
		if(bom[i][j] == '1' && !exp[i][j])cout << '1';
		else cout << '0';
	    }
	    cout << endl;
	}
    }
    return 0;
}
