#include<stdio.h>

#define min(a, b) (a>b?b:a)

int a = (1 << 30), p[3], n, i, j;

int main(){
    scanf("%d", &n);
    for(i = 0;i < n;i++){
	scanf("%d",p + i);
	a = min(a, p[i]);
    }
    for(i = 1;i <= a;i++){
	int x = 1;
	for(j = 0;j < n;j++){
	    if(p[j]%i)x=0;
	}
	if(x)
	    printf("%d\n", i);
    }
    return 0;
}
