#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, int> number;
vector<int> source[109];
int cost[109];
string str;

int solve(int x){
  int ans = 0;
  if(source[x].empty())return cost[x];
  for(int i = 0;i < source[x].size();i++){
    ans += solve(source[x][i]);
  }
  return min(cost[x], ans);
}

int main(){
  int n, p, m, k;
  while(1){
    number.clear();
    for(int i = 0;i < 109;i++)source[i].clear();
    cin >> n;
    if(n == 0)return 0;
    for(int i = 0;i < n;i++){
      cin >> str >> p;
      number[str] = i;
      cost[i] = p;
    }
    cin >> m;
    for(int i = 0;i < m;i++){
      cin >> str >> k;
      int num = number[str];
      for(int j = 0;j < k;j++){
	cin >> str;
	source[num].push_back(number[str]);
      }
    }
    cin >> str;
    cout << solve(number[str]) << endl;
  }
}
