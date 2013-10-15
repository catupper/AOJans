#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int weight, n, v, w, dp[1050];
int main(){
    int t = 0;
    while(cin >> weight, weight){
	fill(dp, dp + 1050, 0);
	t++;
	cin >> n;
	for(int i = 0;i < n;i++){
	    scanf("%d,%d", &v, &w);
	    for(int j = 1000;j >= 0;j--){
		if(j - w >= 0)
		    dp[j] = max(dp[j], dp[j - w] + v);
	    }
	}
	int now = weight;
	for(int i = weight;i >= 0;i--){
	    if(dp[i] >= dp[now])now = i;
	}
	cout << "Case " << t << ":" << endl;
	cout << dp[now] << endl;
	cout << now << endl;
    }
    return 0;
}
