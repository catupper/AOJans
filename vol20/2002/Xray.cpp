#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int l[26], r[26], top[26], bottom[26], h, w, d;
bool flag[26], come[26];
string str[55];
vector<int> front[26];

void my_unique(vector<int>& x){
    sort(x.begin(), x.end());
    vector<int>::iterator it = unique(x.begin(), x.end());
    x.erase(it, x.end());
}

int loop(int x){
    if(come[x])return true;
    bool res = false;
    come[x] = true;
    for(int i = 0;i < front[x].size();i++){
	res |= loop(front[x][i]);
    }
    come[x] = false;
    return res;
}

int main(){
    cin >> d;
    while(d--){
	fill(l, l + 26, 100);
	fill(r, r + 26, -1);
	fill(bottom, bottom + 26, 100);
	fill(top, top + 26, -1);
	cin >> h >> w;
	for(int i = 0;i < h;i++){
	    cin >> str[i];
	    for(int j = 0;j < w;j++){
		if(str[i][j] == '.')continue;
		int tmp = str[i][j] - 'A';
		flag[tmp] = true;
		l[tmp] = min(l[tmp], i);
		bottom[tmp] = min(bottom[tmp], j);
		r[tmp] = max(r[tmp], i);
		top[tmp] = max(top[tmp], j);
	    }
	}
	bool res = true;
	for(int s = 0;s < 26;s++){
	    front[s].clear();
	    if(!flag[s])continue;
	    for(int i = l[s];i <= r[s];i++){
		for(int j = bottom[s];j <= top[s];j++){
		    if(str[i][j] == '.')res = false;
		    if(str[i][j] != 'A' + s){
			front[s].push_back(str[i][j] - 'A');
		    }
		}
	    }
	    my_unique(front[s]);
	}
	for(int i = 0;res && i < 26;i++){
	    if(loop(i))res = false;
	}
	if(res)
	    cout << "SAFE" << endl;
	else
	    cout << "SUSPICIOUS" << endl;
    }
    return 0;
}
