#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int u[1050];

int p(int x){
    if(x == u[x])return x;
    return u[x] = p(u[x]);
}

void unin(int a, int b){
    a = p(a);
    b = p(b);
    u[a] = b;
}

struct P{
    P(){};
    P(int a, int b){
	x = a;y = b;
    } 
    int x, y;
    P operator-(P a){
	return P(x - a.x, y - a.y);
    }
    int det(P a){
	return x * a.y - y * a.x;
    }
};

struct L{
    L(){}
    L(int o, int p, int q, int r){
	ax = o;ay = p;bx = q;by = r;
	if(ax == bx){
	    a = 1;
	    b = 0;
	    c = -ax;
	}
	else{
	    a = ay - by;
	    b = bx - ax;
	    c = -(ax * a + b * ay);
	}
	vect = P(ax - bx, ay - by);
    }
    int f(int x, int y){
	return a * x + b * y + c;
    }
    int ax, ay, bx, by, a, b, c;
    P vect;
};

bool cross(L a, L b){
    return (a.f(b.ax, b.ay) * a.f(b.bx, b.by) <= 0 &&
	    b.f(a.ax, a.ay) * b.f(a.bx, a.by) <= 0);
}

bool round(L a, L b){
    return a.vect.det(P(a.ax - b.ax, a.ay - b.ay)) <= 0;
}

int main(){
    int n, q;
    L square[1050][4];
    int ax, ay, bx, by , cx, cy, dx, dy;
    while(cin >> n, n){
	for(int t = 0;t < n;t++){
	    cin >> q;
	    for(int i = 0;i < q;i++){
		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
		square[i][0] = L(ax, ay, bx, by);
		square[i][1] = L(bx, by, cx, cy);
		square[i][2] = L(cx, cy, dx, dy);
		square[i][3]= L(dx, dy, ax, ay);
		u[i] = i;
	    }
	    for(int i = 0;i < q;i++){
		for(int j = 0;j < q;j++){
		    for(int k = 0;k < 4;k++){
			bool ok = true;
			for(int l = 0;l < 4;l++){
			    if(cross(square[i][k], square[j][l]))unin(i, j);	
			    ok &= (round(square[j][l], square[i][k]) == round(square[j][(l + 1) % 4], square[i][k]));
			}
			if(ok)unin(i, j);
		    }
		}
	    }
	    set<int> sq;
	    for(int i = 0;i < q;i++)sq.insert(p(i));
	    cout << sq.size() << endl;
	}
    }
}
