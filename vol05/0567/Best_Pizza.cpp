#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  int n, a, b, cal, pizzas[100];
  scanf("%d%d%d%d", &n, &a, &b, &cal);
  for(int i = 0;i < n;i++){
    scanf("%d", pizzas + i);
  }
  sort(pizzas, pizzas + n, greater<int>());
  int cost = a;
  for(int i = 0;i < n;i++){
    if((cal + pizzas[i]) / (cost + b) >= cal / cost){
      cal += pizzas[i];
      cost += b;
    }
    else break;
  }
  printf("%d\n", cal / cost);
  return 0;
}
