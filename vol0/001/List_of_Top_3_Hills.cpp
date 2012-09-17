#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
  int hills[10];
  for(int i = 0;i < 10;i++){
    scanf("%d",hills + i);
  }
  sort(hills,hills + 10);
  printf("%d\n%d\n%d\n",hills[9],hills[8],hills[7]);
  return 0;
}
