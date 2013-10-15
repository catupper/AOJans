#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;





int ok[] = {0, 3, 6, 1, 4, 7, 2, 5, 8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 4, 8, 2, 4, 6};

int main(){
    while(cin >> str){
	for(int i = 0;i < 24;i += 3){
	    if(str[ok[i]] == str[ok[i + 1]] && str[ok[i]] == str[ok[i + 2]]){
		if(str[ok[i]] == 's')continue;
		cout << str[ok[i]] << endl;
		break;
	    }
	    if(i == 21)cout << 'd' << endl;
	}
    }
}
