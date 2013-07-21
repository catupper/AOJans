#include<iostream>
#include<algorithm>

using namespace std;

int c[] = {1, 4, 1, 4, 1, 2, 1, 2};
int ans[] = {14141212,
	     41412121,
	     14121214,
	     41212141,
	     12121414,
	     21214141,
	     12141412,
	     21414121};
int p[8];
int main(){
    while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> p[6] >> p[7]){
	int lex = 1 << 30, an, rem = 1 << 30;
	for(int i = 0;i < 8;i++){
	    int tmp = 0;
	    for(int j = 0;j < 8;j++){
		tmp += max(p[j] - c[(i + j) % 8], 0);
	    }
	    if(tmp < rem || tmp == rem && ans[i] < lex){
		lex = ans[i];
		an = i;
		rem = tmp;
	    }
	}
	for(int i = 0;i < 8;i++){
	    cout << c[(i + an) % 8];
	    if(i != 7)cout << " ";
	}
	cout << endl;
    }
    return 0;
}
