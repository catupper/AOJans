#include<iostream>
#include<algorithm>

using namespace std;

int pos[15][15], ans[15][15], area[105], x, y;
int tmp[15][15];
bool used[105], one, more;
void solve(int a, int b){
    if(ans[a][b]){
	a++;
	a %= x;
	if(a == 0)b++;
	if(b == y){
	    if(one || more){
		more = true;
		one = false;
	    }
	    else one = true;
	    for(int i = 0;i < x;i++)
		for(int j = 0;j < y;j++)
		    tmp[i][j] = ans[i][j];
	    return ;
	}
	solve(a, b);
	return;
    }
    for(int p = 1;area[p];p++){
	if(used[p])continue;
	for(int i = 1;i * i <= area[p];i++){
	    if(area[p] % i)continue;
	    int j = area[p] / i;
	    if(a + i <= x && b + j <= y){
		bool ok = true, found = false;
		for(int k = a;k < a + i && ok;k++){
		    for(int l = b;l < b + j && ok;l++){
			if(pos[k][l] != 0 && pos[k][l] != p)ok = false;
			if(ans[k][l] != 0)ok = false;
			if(pos[k][l] == p)found = true;
		    }
		}
		if(ok && found){
		    for(int k = a;k < a + i && ok;k++){
			for(int l = b;l < b + j && ok;l++){
			    ans[k][l] = p;
			}
		    }
		    solve(a, b);
		    for(int k = a;k < a + i && ok;k++){
			for(int l = b;l < b + j && ok;l++){
			    ans[k][l] = 0;
			}
		    }
		}
	    }
	    if(i == j)continue;
	    swap(i, j);
	    
	    if(a + i <= x && b + j <= y){
		bool ok = true, found = false;
		for(int k = a;k < a + i && ok;k++){
		    for(int l = b;l < b + j && ok;l++){
			if(pos[k][l] != 0 && pos[k][l] != p)ok = false;
			if(ans[k][l] != 0)ok = false;
			if(pos[k][l] == p)found = true;
		    }
		}
		if(ok && found){
		    for(int k = a;k < a + i && ok;k++){
			for(int l = b;l < b + j && ok;l++){
			    ans[k][l] = p;
			}
		    }
		    solve(a, b);
		    for(int k = a;k < a + i && ok;k++){
			for(int l = b;l < b + j && ok;l++){
			    ans[k][l] = 0;
			}
		    }
		}
	    }

	    swap(i, j);

	}
    }
}

int main(){
    int n, a, b;
    while(cin >> x >> y >> n, n){
	swap(x, y);
	one = more = false;
	for(int i = 0;i < x;i++)
	    for(int j = 0;j < y;j++)
		ans[i][j] = 0;
	for(int i = 0;i < n;i++){
	    cin >> a >> b;
	    area[a] = b;
	}
	area[n + 1] = 0;
	for(int i = 0;i < x;i++)
	    for(int j = 0;j < y;j++)
		cin >> pos[i][j];
	solve(0, 0);
	if(one){
	    for(int i = 0;i < x;i++){
		for(int j = 0;j < y;j++){
		    if(j)cout << " ";
		    cout  << tmp[i][j];
		}
		cout << endl;
	    }
	}
	else
	    cout << "NA" << endl;
    }
    return 0;
}
