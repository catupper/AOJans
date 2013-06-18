#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
#define to_rad(x) ((double)x * M_PI / 180)
#define sq(x) (x * x)
#define INF (1 << 30)
#define EPS (1e-10)
typedef pair<double, double> P;
typedef pair<double, int> iP;
typedef pair<P, P> L;

double dist[1050];
L lines[1050];
int n, m, l, x, y, a, r;
bool done[1050];

P point(P c, double a, double r){
    r = to_rad(r);
    double x = c.first, y = c.second;
    x += a * cos(r);
    y += a * sin(r);
    return P(x, y);
}

double point_line(L l, P p){
    double p1 = hypot(l.first.first - p.first, l.first.second - p.second);
    double p2 = hypot(l.second.first - p.first, l.second.second - p.second);
    double p3 = hypot(l.first.first - l.second.first, l.first.second - l.second.second);
    if(sq(p1) > sq(p2) + sq(p3))return p2;
    if(sq(p2) > sq(p1) + sq(p3))return p1;

    double b = l.first.first - l.second.first;
    double a = l.second.second - l.first.second;
    double c = - (a * l.first.first + b * l.first.second);
    if(abs(a) < EPS && abs(b) < EPS)return 0;
    return abs(a * p.first + b * p.second + c) / sqrt(a * a + b * b);
}

bool cross(L l, L m){
    double a, b, c;
    b = l.first.first - l.second.first;
    a = l.second.second - l.first.second;
    c = - (a * l.first.first + b * l.first.second);
    if(abs(a * m.first.first + b * m.first.second + c) < EPS)return true;
    if(abs(a * m.second.first + b * m.second.second + c) < EPS)return true;
    if((a * m.first.first + b * m.first.second + c > -EPS) ^ (a * m.second.first + b * m.second.second + c > -EPS))return true;
    return false;
}

double line_dist(L a, L b){
    if(cross(a, b) && cross(b, a))return 0;
    double res = INF;
    res = min(res, point_line(a, b.first));
    res = min(res, point_line(a, b.second));
    res = min(res, point_line(b, a.first));
    res = min(res, point_line(b, a.second));
    return res;
}

double dijkstra(int s, int g){
    priority_queue<iP, vector<iP>, greater<iP> > pq;
    fill(dist, dist + n * 5, INF);
    fill(done, done + n * 5, false);
    dist[s] = 0;
    pq.push(iP(0, s));
    while(!pq.empty()){
	iP tmp = pq.top();pq.pop();
        int from = tmp.second;
	if(dist[from] < tmp.first)continue;
	done[from] = true;
	for(int i = 0;i < n * 5;i++){
	    if(dist[i] > dist[from] + line_dist(lines[i], lines[from])){
		dist[i] = dist[from] + line_dist(lines[i], lines[from]);
		pq.push(iP(dist[i], i));
	    }
	}
    }
    return dist[g];
}


int main(){
    while(true){
	cin >> n >> m >> l;
	if(n == 0 && m == 0 && l == 0)return 0;
	for(int i = 0;i < n;i++){
	    cin >> x >> y >> a >> r;
	    P c = P(x, y);
	    int j;
	    for(j = 0, r += 18;j < 5;j++, r += 72){
		lines[i * 5 + j] = L(point(c, a, r), point(c, a, r + 144));
	    }
	}
	cout << dijkstra(m * 5 - 1, l * 5 - 1) << endl;
    }
}
