#include<stdio.h>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  while(true){
    int n, m, a, b;
    scanf("%d", &n);
    if(n == 0)return 0;
    set<int> times;
    map<int, int> people;
    for(int i = 0;i < n;i++){
      scanf("%d%d%d", &m, &a, &b);
      times.insert(a);
      times.insert(b);
      if(people.find(a) == people.end()){
	people[a] = 0;
      }
      if(people.find(b) == people.end()){
	people[b] = 0;
      }
      people[a] += m;
      people[b] -= m;
    }
    int weight = 0;
    bool res = true;
    set<int>::iterator it;
    for(it = times.begin();it != times.end();it++){
      weight += people[*it];
      if(weight > 150){
	res = false;
	break;
      }
    }
    if(res)puts("OK");
    else puts("NG");
  }
}
