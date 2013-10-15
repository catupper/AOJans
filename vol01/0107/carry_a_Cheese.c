#include<stdio.h>

int main(){
    int a, b, c, p, i;
    while(scanf("%d %d %d", &a, &b, &c), a | b | c){
	int m;
	if(a >= b && a >= c)m = b * b + c * c;
	if(b >= a && b >= c)m = a * a + c * c;
	if(c >= a && c >= b)m = a * a + b * b;
	scanf("%d", &p);
	for(i = 0;i < p;i++){
	    scanf("%d", &a);
	    if(a * a * 4 > m)puts("OK");
	    else puts("NA");
	}
    }
    return 0;
}
