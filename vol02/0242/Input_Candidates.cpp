#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, string> P;

vector<P> words;

char str[1050], c;
int n;
int main(){
    while(cin >> n, n){
	map<string, int> counter;
	for(int i = 0;i < n;i++){
	    while(true){
		scanf(" %s%c", str, &c);
		counter[str]++;
		if(c == '\n')break;
	    }
	}
	cin >> c;
	words.clear();
	map<string, int>::iterator it = counter.begin();
	while(it != counter.end()){
	    words.push_back(P(-(it->second), it->first));
	    it++;
	}
	sort(words.begin(), words.end());
	int ok = 0;
	for(int i = 0;i < words.size();i++){
	    if((words[i].second)[0] == c){
		if(ok == 0)ok = 1;
		else cout << " ", ok++;
		cout << words[i].second;
	    }
	    if(ok == 5)break;
	}
	if(ok == 0)cout << "NA";
	cout << endl;
    }
    return 0;
}
