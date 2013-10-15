#include<iostream>
#include<algorithm>

using namespace std;

bool used[10];

int table[15][1050][1 << 10];
int z = (1 << 10) - 1;
int solve(int x, int y){
    if(x > 10)return 0;
    if(x < 0)return 0;
    if(y > 1050)return 0;
    if(y < 0)return  0;
    int &res = table[x][y][z];
    if(res != -1)return res;
    res = 0;
    if(x == 0)return res = (y == 0);
    for(int i = 0;i < 10;i++){
	if(used[i])continue;
	used[i] = true;
	z ^= 1 << i;
	res += solve(x - 1, y - x * i);
	z ^= 1 << i;
	used[i] = false;
    }
    return res;
}

int main(){
    for(int i = 0;i < 15;i++)
	for(int j = 0;j < 1050;j++)
	    for(int k = 0;k < (1 << 10);k++)
	    table[i][j][k] = -1;
    int n, s;
    while(cin >> n >> s)
	cout << solve(n, s) << endl;
    return 0;
}
