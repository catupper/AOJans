#include<stdio.h>

char *ans[10];
int n, p, i;
int main(){
    ans[0] = "1111110";
    ans[1] = "0110000";
    ans[2] = "1101101";
    ans[3] = "1111001";
    ans[4] = "0110011";
    ans[5] = "1011011";
    ans[6] = "1011111";
    ans[7] = "1110010";
    ans[8] = "1111111";
    ans[9] = "1111011";
    while(scanf("%d", &n),~n){
	char *now = "00000000";
	while(n--){
	    scanf("%d", &p);
	    for(i = 6;i >= 0;i--){
		printf("%d", !(ans[p][i] == now[i]));
	    }
	    puts("");
	    now = ans[p];
	}
    }
    return 0;
}
