#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  long long int n, h, d, hp, maxhp, damage = 0, ans = 0;
  deque<pair<long long int, long long int> > izumi;
  scanf("%lld%lld", &n, &hp);
  maxhp = hp;
  for(int i = 0;i < n - 1;i++){
    scanf("%lld%lld", &d, &h);
    while(!izumi.empty() && izumi.back().first < h){
      izumi.pop_back();
    }
    izumi.push_back(make_pair(h, damage));
    damage += d;
    while(hp <= damage){
      long long int tmphp = hp ;
      while(!izumi.empty() && tmphp + izumi.front().first - izumi.front().second > maxhp){
	hp = max(hp, izumi.front().second + maxhp);
	izumi.pop_front();
      }
      if(!izumi.empty()){
	hp = max(hp, tmphp + izumi.front().first);
	int tmp = max(0ll, min((damage - hp) / izumi.front().first, (izumi.front().second + maxhp - hp) / izumi.front().first));
	ans += tmp;
	hp += tmp * izumi.front().first;
      }
      ans++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
