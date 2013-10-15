#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int cnt[10];
string str;
bool done;
bool ok(int pos){
    if(pos == 10)return true;
    if(cnt[pos] == 0)return ok(pos + 1);
    if(cnt[pos] >= 3){
	cnt[pos] -= 3;
	if(ok(pos)){
	    cnt[pos] += 3;
	    return true;
	}
	cnt[pos] += 3;
    }
    if(cnt[pos] >= 2 && !done){
	done = true;
	cnt[pos] -= 2;
	if(ok(pos)){
	    done = false;
	    cnt[pos] += 2;
	    return true;
	}
	cnt[pos] += 2;
	done = false;
    }
    if(pos > 7)return false;
    if(cnt[pos] && cnt[pos + 1] && cnt[pos + 2]){
	cnt[pos]--;
	cnt[pos + 1]--;
	cnt[pos + 2]--;
	if(ok(pos)){
	    cnt[pos]++;
	    cnt[pos + 1]++;
	    cnt[pos + 2]++;
	    return true;
	}
	cnt[pos]++;
	cnt[pos + 1]++;
	cnt[pos + 2]++;
    }
    return false;
}

int main(){
    while(cin >> str){
	done = false;
	fill(cnt, cnt + 10, 0);
	vector<int> ans;
	for(int i = 0;i < 13;i++){
	    cnt[str[i] - '0']++;
	}
	for(int i = 1;i <= 9;i++){
	    if(cnt[i] == 4)continue;
	    cnt[i]++;
	    if(ok(1))ans.push_back(i);
	    cnt[i]--;
	}
	for(int i = 0;i < ans.size();i++){
	    cout << ans[i];
	    if(i != ans.size() - 1) cout << " ";
	}
	if(ans.size() == 0)cout<< 0;
	cout << endl;
    }
    return 0;
}
