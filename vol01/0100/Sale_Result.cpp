#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    vector<int> num;
    set<int> used;
    map<int, long long> sales;
    int a, b, c;
    for(int i = 0;i < n;i++){
      cin >> a >> b >> c;
      num.push_back(a);
      if(sales.count(a) == 0)sales[a] = 0;
      sales[a] += b * c;
    }
    bool ok = false;
    for(int i = 0;i < n;i++){
      int p = num[i];
      if(used.count(p))continue;
      used.insert(p);
      if(sales[p] >= 1000000){
	cout << p << endl;
	ok = true;
      }
    }
    if(!ok)cout << "NA" << endl;
  }
  return 0;
}
