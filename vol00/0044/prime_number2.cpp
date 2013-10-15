#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int p[105000];
vector<int> prime;
int main(){
    for(int i = 2;i * i <= 105000;i++){
	if(p[i])continue;
	for(int j = i * i;j < 105000;j += i){
	    p[j] = 1;
	}
    }
    for(int i = 2;i < 105000;i++){
	if(p[i] == 0)
	    prime.push_back(i);
    }
    int n;
    while(cin >> n){
	int up = *(upper_bound(prime.begin(), prime.end(), n));
	int less = *(lower_bound(prime.begin(), prime.end(), n) - 1);
	cout << less << " " << up << endl;
    }
    return 0;
}
