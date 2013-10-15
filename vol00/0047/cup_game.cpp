#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    char now = 'A', a, b;
    while(~scanf(" %c,%c", &a, &b)){
	if(a == now)now = b;
	else if(b == now)now = a;
    }
    printf("%c\n", now);
    return 0;
}
