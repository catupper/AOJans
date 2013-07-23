#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int a, b;
  while(cin >> a >> b, a | b){
    char ans = 'A';
    int m = a + b;
    for(int i = 1;i < 5;i++){
      cin >> a >> b;
      if(a + b > m){
	ans = i + 'A';
	m = a + b;
      }
    }
    cout << ans << " " << m << endl;
  }
  return 0;
}
