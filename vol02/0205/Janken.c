#include<stdio.h>

int main(){
  while(1){
    int i, t[5], used[] = {0, 0, 0};
    for(i = 0;i < 5;i++){
      scanf("%d", t + i);
      used[t[i] % 3]++;
    }
    if(t[0] == 0)return 0;
    if(used[0] && used[1] && used[2]){
      for(i = 0;i < 5;i++)
	puts("3");
    }
    else if(used[0] == 0){
      if(used[1] == 0 || used[2] == 0){
	for(i = 0;i < 5;i++)
	  puts("3");
      }
      else{
	for(i = 0;i < 5;i++){
	  if(t[i] == 1)
	    puts("1");
	  else
	    puts("2");
	}
      }
    }
    else if(used[1] == 0){
      if(used[2] == 0){
	for(i = 0;i < 5;i++)
	  puts("3");
      }
      else{
	for(i = 0;i < 5;i++){
	  if(t[i] == 2)
	    puts("1");
	  else
	    puts("2");
	}
      }
    }
    else{
      for(i = 0;i < 5;i++){
	if(t[i] == 3)
	  puts("1");
	else
	  puts("2");
      }
    }
  }
}
