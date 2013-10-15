#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

string str;
int n;

map<string, vector<int> > dict;

int main(){
    while(cin >> str >> n){
	dict[str].push_back(n);
    }
    map<string, vector<int> >::iterator it = dict.begin();
    while(it != dict.end()){
	cout << it->first << endl;
	sort(it->second.begin(), it->second.end());
	for(int i = 0;i < it->second.size();i++){
	    if(i != 0)cout << " ";
	    cout << it->second.at(i);
	}
	cout << endl;
	it++;
    }
    return 0;
}
