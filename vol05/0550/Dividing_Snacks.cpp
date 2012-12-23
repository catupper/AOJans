#include<iostream>
#include<algorithm>
using namespace std;
#define INF (1 << 30)
int table[2][10500][2], n, tmp;

int main(){
  cin >> n;
  for(int i = 0;i < 2;i++)
    for(int j = 0;j < 10500;j++)
      for(int k = 0;k < 2;k++)table[i][j][k] = INF;
  table[1][1][0] = table[1][0][1] = 0;
  for(int i = 0;i < n - 1;i++){
    cin >> tmp;
    for(int j = 0;j < 10400;j++){
      if(j != 0)     
	table[i & 1][j][0] = min(table[(i + 1) & 1][j - 1][0], table[(i + 1) & 1][j - 1][1] + tmp);
      table[i & 1][j][1] = min(table[(i + 1) & 1][j][1], table[(i + 1) & 1][j][0] + tmp);
    }
  }
  cout << table[(n - 1) & 1][n / 2][0] << endl;
  return 0;
}
