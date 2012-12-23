#include<iostream>
#include<algorithm>
using namespace std;

int icicle[105000], n, l, table[105000];

int snap(int x){
  if(table[x] != 0)return table[x];
  int res = 0;
  if(icicle[x - 1] > icicle[x]){
    res = max(res, snap(x - 1));
  }
  if(icicle[x + 1] > icicle[x]){
    res = max(res, snap(x + 1));
  }
  res += l - icicle[x];
  return table[x] = res;
}

int main(){
  cin >> n >> l;
  for(int i = 1;i <= n;i++){
    cin >> icicle[i];
  }
  int res = 0;
  for(int i = 1;i <= n;i++){
    res = max(res, snap(i));
  }
  cout << res << endl;
}
