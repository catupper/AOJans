#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;

string fb(int x){
    if(x % 15 == 0)return "FizzBuzz";
    if(x % 3 == 0)return "Fizz";
    if(x % 5 == 0)return "Buzz";
    char c[1050];
    sprintf(c, "%d", x);
    string res = c;
    return res;
}

int main(){
    int a, b;
    while(cin >> a >> b, a | b){
	set<int> alive;
	int left = a, p = 0;
	for(int i = 0;i < a;i++)alive.insert(i);
	set<int>::iterator it = alive.begin();
	for(int i = 1;i <= b;i++){
	    string u;
	    cin >> u;
	    if(left == 1)continue;
	    if(u != fb(i)){
		alive.erase(it++);
		left--;
	    }
	    else{
		it++;
	    }
	    if(it == alive.end())it = alive.begin();
	}
	it = alive.begin();
	while(it != alive.end()){
	    if(it != alive.begin())cout <<" ";
	    cout << 1 + *it;
	    it++;
	}
	cout << endl;
    }
    return 0;
}
