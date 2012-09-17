#include<stdio.h>

int main(){
  while(1){
    int n,i;
    int sum = 1;
    int top = 1;
    int front = 2;
    int right = 3;

    scanf("%d", &n);
    if(n == 0)break;
    for(i = 0;i < n;i++){
      char str[10];
      scanf("%s", str);
      int nt = top;
      int nf = front;
      int nr = right;
      switch(str[0]){
      case 'N':
	nt = front;
	nf = 7 - top;
	break;
	
      case 'E':
	nt = 7 - right;
	nr = top;
	break;
	
      case 'W':
	nt = right;
	nr = 7 - top;
	break;
	
      case 'S':
	nt = 7 - front;
	nf = top;
	break;
	
      case 'R':
	nf = right;
	nr = 7 - front;
	break;
	
      case 'L':
	nf = 7 - right;
	nr = front;
	break;
      }
      top = nt;
      front = nf;
      right = nr;
      sum += top;
    }
    printf("%d\n", sum);
  }
  return 0;
}
