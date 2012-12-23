#include<iostream>
#include<algorithm>
using namespace std;

int answer[10500];

void add_gyakusu(int x){
  int t = 1;
  for(int i = 0;i < 10200;i++){
    answer[i] += t / x;
    t %= x;
    t *= 10;
  }
}

void kuriagari(){
  for(int i = 10199;i >= 0;i--){
    answer[i - 1] += answer[i] / 10;
    answer[i] %= 10;
  }
}

int main(){
  int n, k, m, r;
  while(true){
    cin >> n >> k >> m >> r;
    fill(answer, answer + 10500, 0);
    if(n + k + m + r == 0)return 0;
    add_gyakusu(n);
    if(m == 1){
      for(int i = 1;i < n;i++){
	add_gyakusu(i * n);	
      }
    }
    kuriagari();
    cout << answer[0]  <<'.';
    for(int i = 1;i <= r;i++){
      cout << answer[i];
    }
    cout << endl;
  }
}
