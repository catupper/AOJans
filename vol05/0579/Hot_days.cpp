#include<iostream>
#include<algorithm>
using namespace std;

int d, n, day[222], cloth[222][4], dp[222][222], res;

int main(){
    cin >> d >> n;
    for(int i = 0;i < d;i++){
	cin >> day[i];
    }
    for(int i = 0;i < n;i++){
	cin >> cloth[i][0] >> cloth[i][1] >> cloth[i][3];
    }
    for(int i = 0;i < d;i++){
	for(int j = 0;j < n;j++){
	    if(i == 0){
		if(cloth[j][0] <= day[i] && day[i] <= cloth[j][1]){
		    dp[i][j] = 0;
		}
		else{
		    dp[i][j] = -1;
		}
		continue;
	    }
	    if(!(cloth[j][0] <= day[i]  && day[i] <= cloth[j][1])){
		dp[i][j] = -1;
		continue;
	    }
	    for(int k = 0;k < n;k++){
		if(dp[i - 1][k] == -1)continue;
		dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(cloth[j][3] - cloth[k][3]));
	    }
	}
    }
    for(int i = 0;i < n;i++){
	res = max(res, dp[d - 1][i]);
    }
    cout << res << endl;
    return 0;
}
