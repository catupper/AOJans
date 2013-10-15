#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int sum = 0, cnt = 0, n = 0, x, y;
    while(~scanf("%d,%d", &x, &y)){
	sum += x * y;
	cnt++;
	n += y;
    }
    n *= 10;
    n /= cnt;
    n += 5;
    n /= 10;
    printf("%d\n%d\n", sum, n);
    return 0;
}
