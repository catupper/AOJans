#include<stdio.h>
#include<string.h>

int main(){
  char str[100000];
  while(scanf("%s", str) != EOF){
    int i, joi = 0, ioi = 0;
    for(i = 0;i < strlen(str) - 3;i++){
      if(str[i] =='J' && str[i + 1] == 'O' && str[i + 2] == 'I'){
	joi++;
      }
      if(str[i] =='I' && str[i + 1] == 'O' && str[i + 2] == 'I'){
	ioi++;
      }
    }
    printf("%d\n%d\n", joi, ioi);
  }
  return 0;
}
