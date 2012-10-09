#include<stdio.h>
#include<string.h>

char stra[100], str[100], len;
void zure(int i){
  int j;
  for(j = 0;j < len;j++){
    if(stra[j] < 'a' || stra[j] > 'z')str[j] = stra[j];
    else str[j] = (stra[j] - 'a' + i) % 26 + 'a';
  }
  str[j] = '\0';
}

int main(){
  int x, j, i;
  while(scanf(" %[^\n]", stra) != EOF){
    len = strlen(stra);
    for(i = 0;i < 26;i++){
      int ok = 0;
      zure(i);
      for(j = 0;j < len - 4;j++){
	if(str[j] == 't' &&  str[j + 1] == 'h' && str[j + 2] == 'a' && str[j + 3] == 't'){
	  ok = 1;
	  break;
	}
	if(str[j] == 't' &&  str[j + 1] == 'h' && str[j + 2] == 'i' && str[j + 3] == 's'){
	  ok = 1;
	  break;
	}
	if(str[j] == 't' &&  str[j + 1] == 'h' && str[j + 2] == 'e'){
	  ok = 1;
	break;
	}
	if(str[j + 1] == 't' && str[j + 2] == 'h' && str[j + 3] == 'e'){
	  ok = 1;
	  break;
	}
      }
      if(ok == 1){
	puts(str);
	break;
      }
    }
  }
  return 0;
}
