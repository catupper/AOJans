#include<cstdio>
#include<cstring>
int main(){
    char input[1050];
    int p = 0;
    while(~(input[p]=getchar()))p++;
    input[p] = 0;
    for(int i = 0;i < p - 5;i++){
	if(strncmp(input + i, "peach", 5) == 0){
	    input[i] = 'a';
	    input[i + 1] = 'p';
	    input[i + 2] = 'p';
	    input[i + 3] = 'l';
	    input[i + 4] = 'e';
	}
	else if(strncmp(input + i, "apple", 5) == 0){
	    input[i] = 'p';
	    input[i + 1] = 'e';
	    input[i + 2] = 'a';
	    input[i + 3] = 'c';
	    input[i + 4] = 'h';
	}
    }
    printf("%s", input);
    return 0;
}
