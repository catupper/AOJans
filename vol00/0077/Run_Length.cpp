#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    char c, d;
    while(~(c = getchar())){
	if(c == '@'){
	    c = getchar();
	    d = getchar();
	    for(int i = 0;i < c - '0';i++){
		putchar(d);
	    }
	}
	else{
	    putchar(c);
	}
    }
    return 0;
}
