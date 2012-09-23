#include<stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
int main(){
  int n, m, i;
  while(1){
    scanf("%d", &n);
    if(n == 0)return 0;
    scanf("%d\n", &m);
    int ppo = 0, po = 0, ppi = 0, pi = 0, res = 0;
    for(i = 0;i < m;i++){
      char c = getchar();
      int ni = 0, no = 0;
      if(c == 'I'){
	ni = ppi + 1;
	if(n <= min(ni - 1, po)){
	  res++;
	}
      }
      else{
	no = ppo + 1;
      }
      ppo = po;
      ppi = pi;
      po = no;
      pi = ni; 
    }
    printf("%d\n",res);
  }
}
