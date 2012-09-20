#include<cstdio>
#include<deque>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  while(1){
    int n, m, p, q, r;
    scanf("%d", &n);
    if(n == 0)return 0;
    scanf("%d%d%d%d", &m, &p, &q, &r);
    deque<pair<int, int> > mountain, mounta, mountb;
    mountain.push_back(make_pair(1, n));
    for(int i = 0;i < m;i++){
      int x, y, j = 0;
      scanf("%d%d", &x, &y);
      
      while(j + mountain[0].second - mountain[0].first + 1 < x){
	j += mountain[0].second - mountain[0].first + 1;
	mounta.push_back(mountain[0]);
	mountain.pop_front();
      }
      mounta.push_back(make_pair(mountain[0].first ,mountain[0].first + x - j - 1));
      if(mountain[0].second == mountain[0].first + x - j - 1)mountain.pop_front();
      else mountain[0].first += x - j;
      j = x;

      while(j + mountain[0].second - mountain[0].first + 1 < y){
	j += mountain[0].second - mountain[0].first + 1;
	mountb.push_back(mountain[0]);
	mountain.pop_front();
      }
      mountb.push_back(make_pair(mountain[0].first ,mountain[0].first + y - j - 1));
      if(mountain[0].second == mountain[0].first + y - j - 1)mountain.pop_front();
      else mountain[0].first += y - j;
      
      while(!mountb.empty()){
	mountain.push_back(mountb[0]);
	mountb.pop_front();
      }
      while(!mounta.empty()){
	mountain.push_back(mounta[0]);
	mounta.pop_front();
      }
    }
    int j = 0;
    while(j + mountain[0].second - mountain[0].first + 1 < p - 1){
      j += mountain[0].second - mountain[0].first + 1;
      mountain.pop_front();
    }
    if(mountain[0].second == mountain[0].first + p - j - 2)mountain.pop_front();
    else mountain[0].first += p - j - 1;
    j = p - 1;
    
    int res = 0;
    while(j + mountain[0].second - mountain[0].first + 1 < q){
      res += max(0, min(r, mountain[0].second) - mountain[0].first + 1);
      j += mountain[0].second - mountain[0].first + 1;
      mountain.pop_front();      
    }
    res += max(0, min(r, mountain[0].first + q - j - 1) - mountain[0].first + 1);
    printf("%d\n", res);
  }
}
