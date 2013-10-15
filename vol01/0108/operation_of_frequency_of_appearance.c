#include<stdio.h>

int same(int *x, int *y, int n){
    int i;
    for(i = 0;i < n;i++){
	if(x[i] != y[i])return 0;
    }
    return 1;
}

void swap(int *x, int *y){
    int p = *x;
    *x = *y;
    *y = p;
}

int main(){
    int i, j, n;
    while(scanf("%d", &n), n){
	int a[n], b[n], res = 0;
	for(i = 0;i < n;i++)scanf("%d", a + i);
	while(1){
	    for(i = 0;i < n;i++){
		b[i] = 0;
		for(j = 0;j < n;j++){
		    if(a[j] == a[i])b[i]++;
		}
	    }
	    if(same(a, b, n))break;
	    for(i = 0;i < n;i++)swap(a + i, b + i);
	    res++;
	}
	printf("%d\n", res);
	for(i = 0;i < n;i++){
	    if(i != 0)printf(" ");
	    printf("%d", a[i]);
	}
	puts("");
    }
    return 0;
}
