#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> T;
int main(){
  int n, x;
  char c;
  while(cin >> n, n){
    map<T, char> mem;
    for(int i = 0;i < n;i++){
      T tmp = T(P(0, 0), i);
      cin >> c;
      for(int j = 1;j < n;j++){
	cin >> x;
	if(x == 0)tmp.first.first--;
	if(x == 1)tmp.first.second++;
      }
      mem[tmp] = c;
    }
    map<T, char>::iterator it = mem.begin();
    while(it != mem.end()){
      cout << it->second << endl;
      it++;
    }
  }
  return 0;
}
