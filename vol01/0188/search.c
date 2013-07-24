#include<stdio.h>

int main(){
    int n, num[1050], x, i;
    while(scanf("%d", &n), n){
	for(i = 0;i < n;i++){
	    scanf("%d", num + i);
	}
	scanf("%d", &x);
	int bottom = 0, top = n, res = 0;;
	while(top > bottom){
	    res++;
	    int mid = (bottom + top - 1) / 2;
	    if(num[mid] == x)break;
	    if(num[mid] < x)bottom = mid + 1;
	    else top = mid;
	}
	printf("%d\n", res);
    }
    return 0;
}
