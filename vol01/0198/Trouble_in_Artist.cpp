#include<algorithm>
#include<iostream>
#include<string>
#include<set>
using namespace std;
string face[6];
int n;
int main(){
  while(cin >> n, n){
    set<string> ans;
    for(int j = 0;j < n;j++){
      cin >> face[0] >> face[1] >> face[2] >> face[3] >> face[4] >> face[5];
      string p;
      for(int i = 0;i < 4;i++){
	if(face[0] == "Blue")break;
	swap(face[0], face[1]);
	swap(face[1], face[5]);
	swap(face[5], face[4]);
      }
      for(int i = 0;i < 4;i++){
	if(face[0] == "Blue")break;
	swap(face[0], face[2]);
	swap(face[2], face[5]);
	swap(face[5], face[3]);
      }
      for(int i = 1;i < 5;i++){
	if(i == 1)p = face[i];
	p = min(p, face[i]);
      }
      while(face[1] != p){
	swap(face[1], face[2]);
	swap(face[2], face[4]);
	swap(face[4], face[3]);
      }
      string res ="";
      for(int i = 0;i < 6;i++){
	res += face[i][0];
      }
      ans.insert(res);
    }
    cout << n - ans.size() << endl;
  }
  return 0;
}
