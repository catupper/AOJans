#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int n;
    int nums[105][105];
    while(cin >> n, n){
	int x = n / 2 + 1, y = n / 2;
	for(int i = 0;i < n;i++)for(int j = 0;j < n;j++)nums[i][j] = 0;
	for(int i = 1;i <= n * n;i++){
	    nums[x][y] = i;
	    x++;y++;
	    x%=n;y%=n;
	    if(nums[x][y]){
		x++;y+=n-1;
		x%=n;y%=n;
	    }
	}
	for(int i = 0;i < n;i++){
	    for(int j = 0;j < n;j++){
		printf("%4d",nums[i][j]);
	    }
	    cout << endl;
	}
    }
    return 0;
}
