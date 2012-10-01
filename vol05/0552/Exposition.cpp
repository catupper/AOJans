#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int n, used[100000];
pair<int, int> w[100000], s[100000];
int check[2][100000];

bool ok(int d){
  memset(check, 0, sizeof(check));
  

  check[0][w[0].second] = 2;
  int upper = w[0].first, under = w[n - 1].first;
  for(int i = 0;i < n;i++){
    if(abs(upper - w[i].first) > d && abs(under - w[i].first) > d){
      return false;
    }
    if(abs(upper - w[i].first) > d ){
      check[0][w[i].second] = 1;
    }
    if(abs(under - w[i].first) > d){
      check[0][w[i].second] = 2;
    }
  }
  
  check[1][s[0].second] = 2;
  upper = s[0].first;
  under = s[n - 1].first;
  for(int i = 0;i < n;i++){
    if(abs(upper - s[i].first) > d && abs(under - s[i].first) > d){
      return false;
    }
    if(abs(upper - s[i].first) > d){
      check[1][s[i].second] = 1;
    }
    if(abs(under - s[i].first) > d){
      check[1][s[i].second] = 2;
    }
  }
  int differ = 0, both = 0;
  for(int i = 0;i < n;i++){
    if(check[0][i] == 0 || check[1][i] == 0)both++;
    else if(check[0][i] != check[1][i])differ++;
  }
  return (differ == 0 || both + differ == n);
  
}

int main(){
  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    int x, y;
    scanf("%d%d", &x, &y);
    w[i] = make_pair(x + y, i);
    s[i] = make_pair(x - y, i);
  }
  sort(w, w + n);
  sort(s, s + n);
  int up = 1 << 20, down = 0;
  while(up - down > 5){
    int mid = (up + down) / 2;
    if(ok(mid)){
      up = mid;
    }
    else{
      down = mid;
    }
  }
  while(ok(--up));
  printf("%d\n", up + 1);
  return 0;
}
