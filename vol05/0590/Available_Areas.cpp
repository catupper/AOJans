#include<iostream>
#include<algorithm>

using namespace std;

long long n, res;

long long prime(long long x){
    for(long long i = 2;i * i <= x;i++){
	if(x%i==0)return 0;
    }
    return 1;
}
int main(){
    long long p;
    cin >> n;
    for(long long i = 0;i < n;i++){
	cin >> p;
	res += prime(2*p+1);
    }
    cout << res << endl;
}
