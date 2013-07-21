#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int a;
    double h, l;
    int cnt = 0;
    while(~scanf("%d,%lf,%lf", &a, &h, &l)){
	if(h >= 25 * l * l){
	    printf("%d\n", a);
	    cnt++;
	}
    }
    if(cnt == 0){
	puts("該当なし");
    }
    return 0;
}
