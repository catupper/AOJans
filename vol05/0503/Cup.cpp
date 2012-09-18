#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

int maxmove(int x){
  if(x == 0){
    return 0;
  }
  else{
    return maxmove(x - 1) * 3 + 1;
  }
}

int main(){
  while(1){
    int n,m;
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0){
      return 0;
    }
    stack<int> cups[3];
    for(int i = 0;i < 3;i++){
      int k,cup;
      scanf("%d", &k);
      for(int j = 0;j < k;j++){
	scanf("%d", &cup);
	cups[i].push(cup);
      }
    }
    int res = 0, lastto = -1, lastfrom = -1;
    while(cups[0].size() != n && cups[2].size() != n){
      bool moved = false;
      for(int i = 0;i < 3 && !moved;i++){
	for(int j = 0;j < 3 && !moved;j++){
	  if(abs(i - j) != 1 || cups[i].empty() || (j == lastfrom && i == lastto))continue;
	  if(cups[j].empty() || cups[i].top() > cups[j].top()){
	    cups[j].push(cups[i].top());
	    cups[i].pop();
	    res++;
	    lastfrom = i;
	    lastto = j;
	    moved = true;
	  }
	}
      }
    }
    res = min(res, maxmove(n) * 2 - res);
    if(res > m){
      res = -1;
    }
    printf("%d\n", res);
  }
}
