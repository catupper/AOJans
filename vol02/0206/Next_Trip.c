#include<stdio.h>

int main(){
  while(1){
    int done = 0, m, n, i, l;
    scanf("%d", &l);
    if(l == 0)return 0;
    for(i = 1;i <= 12;i++){
      scanf("%d%d", &m, &n);
      if(!done){
	l -= m - n;
	if(l <= 0){
	  printf("%d\n", i);
	  done = 1;
	}
      }
    }
    if(done == 0)
      puts("NA");
  }
}
