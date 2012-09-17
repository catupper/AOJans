#include<stdio.h>
#include<string.h>
int main(){
  int n, m, i, j;
  char translate[999];
  while(1){
    scanf("%d",&n);
    for(i = 0;i < 999;i++)translate[i]=i;
    if(n == 0)return 0;
    for(i = 0;i < n;i++){
      char a, b;
      scanf(" %c %c", &a, &b);
      translate[a] = b;
    }
    scanf("%d", &m);
    for(i = 0;i < m;i++){
      char c;
      scanf(" %c",&c);
      putchar(translate[c]);
    }
    puts("");
  }
}


