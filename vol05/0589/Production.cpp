#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
typedef pair<int, string> P;
map<P, int> d;

int main(){
    int n, p;
    string c;
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> c >> p;
	d[P(c.size(), c)] += p;
    }
    map<P, int>::iterator it = d.begin();
    while(it != d.end()){
	cout << (*it).first.second << " " << (*it).second << endl;
	it++;
    }
    return 0;
}
