#include<stdio.h>

#define max(a, b) (a>b?a:b)
int seg[1 << 21];

void add(int a, int v){
    a += 1 << 20;
    seg[a] += v;
    while(a /= 2){
	seg[a] = max(seg[a * 2], seg[a * 2 + 1]);
    }
}

int solve(){
    int v = 1;
    while(v < (1 << 20)){
	if(seg[v] == seg[v * 2])
	    v = v * 2;
	else
	    v = v * 2 + 1;
    }
    return v - (1 << 20);
}

int main(){
    int i, n, q, a, v;
    scanf("%d%d", &n, &q);
    for(i = 0;i < q;i++){
	scanf("%d%d", &a, &v);
	add(a, v);
	printf("%d %d\n", solve(), seg[1]); 
    }
    return 0;
}
