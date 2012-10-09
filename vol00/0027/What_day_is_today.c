#include<stdio.h>

int month[]={31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
  while(1){
    int a, b, i, sum = 0;
    scanf("%d%d", &a, &b);
    if(a == 0 && b == 0)return 0;
    for(i = 0;i < a - 1;i++)sum += month[i];
    sum += b;
    switch(sum % 7){
    case 0:
      puts("Wednesday");
      break;
    case 1:
      puts("Thursday");
      break;
    case 2:
      puts("Friday");
      break;
    case 3:
      puts("Saturday");
      break;
    case 4:
      puts("Sunday");
      break;
    case 5:
      puts("Monday");
      break;
    case 6:
      puts("Tuesday");
      break;
    }
  }
}
