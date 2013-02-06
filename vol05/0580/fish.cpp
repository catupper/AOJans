#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct square{
    long long x1,y1,z1,x2,y2,z2;
};

vector<square> rippous;
set<long long> xs, ys, zs;
map<long long, long long>transx, transy, transz;
long long field[200][200][200];
long long xx[200], yy[200], zz[200], K, n;
long long res;
int main(){
    cin >> n >> K;
    for(long long i = 0;i < n;i++){
	square tmp;
	cin >> tmp.x1 >> tmp.y1 >> tmp.z1 >> tmp.x2 >> tmp.y2 >> tmp.z2;
	rippous.push_back(tmp);
	xs.insert(tmp.x1);xs.insert(tmp.x2);
	ys.insert(tmp.y1);ys.insert(tmp.y2);
	zs.insert(tmp.z1);zs.insert(tmp.z2);
    }
    set<long long>::iterator it = xs.begin();
    long long ii = 0;
    while(it != xs.end()){
	xx[ii] = *it;
	transx[*it] = ii;
	it++;
	ii++;
    }
    ii = 0;
    it = ys.begin();
    while(it != ys.end()){
	yy[ii] = *it;
	transy[*it] = ii;
	it++;
	ii++;
    }
    ii = 0;
    it = zs.begin();
    while(it != zs.end()){
	zz[ii] = *it;
	transz[*it] = ii;
	it++;
	ii++;
    }
    for(long long i = 0;i < rippous.size();i++){
	square tmp = rippous[i];
	tmp.x1 = transx[tmp.x1];
	tmp.x2 = transx[tmp.x2];
	tmp.y1 = transy[tmp.y1];
	tmp.y2 = transy[tmp.y2];
	tmp.z1 = transz[tmp.z1];
	tmp.z2 = transz[tmp.z2];
	field[tmp.x1][tmp.y1][tmp.z1] ++;
	field[tmp.x2][tmp.y1][tmp.z1] --;
	field[tmp.x1][tmp.y2][tmp.z1] --;
	field[tmp.x2][tmp.y2][tmp.z1] ++;
	field[tmp.x1][tmp.y1][tmp.z2] --;
	field[tmp.x2][tmp.y1][tmp.z2] ++;
	field[tmp.x1][tmp.y2][tmp.z2] ++;
	field[tmp.x2][tmp.y2][tmp.z2] --;
    }
    for(long long i = 1;i < xs.size();i++){
	for(long long j = 0;j < ys.size();j++){
	    for(long long k = 0;k < zs.size();k++){
		field[i][j][k] += field[i - 1][j][k];
	    }
	}
    }
    for(long long i = 0;i < xs.size();i++){
	for(long long j = 1;j < ys.size();j++){
	    for(long long k = 0;k < zs.size();k++){
		field[i][j][k] += field[i][j - 1][k];
	    }
	}
    }
    for(long long i = 0;i < xs.size();i++){
	for(long long j = 0;j < ys.size();j++){
	    for(long long k = 1;k < zs.size();k++){
		field[i][j][k] += field[i][j][k - 1];
	    }
	}
    }
    for(long long i = 0;i < xs.size();i++){
	for(long long j = 0;j < ys.size();j++){
	    for(long long k = 0;k < zs.size();k++){
		if(field[i][j][k] >= K) 
		    res += (xx[i + 1] - xx[i]) * (yy[j + 1] - yy[j]) * (zz[k + 1] - zz[k]);
	    }
	}
    } 
    cout << res << endl;
    return 0;
}

