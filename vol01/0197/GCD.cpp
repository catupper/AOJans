#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int a, b;
  while(cin >> a >> b, a | b){
    if(a < b)swap(a, b);
    int cnt = 0;
    while(b){
      a %= b;
      swap(a, b);
      cnt ++;
    }
    cout << a << " " << cnt << endl;
  }
  return 0;
}
