#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int S[100000], T[50000], n, q, ans;

int main(){
  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    scanf("%d", S + i);
  }
  scanf("%d", &q);
  for(int i = 0;i < q;i++){
    scanf("%d", T + i);
  }
  sort(S, S + n);
  sort(T, T + q);
  int sp = 0;
  for(int i = 0;i < q;i++){
    while(sp < n && S[sp] < T[i])sp++;
    if(S[sp] == T[i])ans++;
  }
  printf("%d\n", ans);
}
