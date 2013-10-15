#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define INF (1 << 30)

struct Node{
    Node(int v){
	val = v;
	minimum = v;
	size = 1;
	l = r = p = 0;
    }
    int val, minimum, size;
    Node *l, *r, *p;
    
    int state(){
	if(p == 0)return 0;
	if(p->l == this)return -1;
	if(p->r == this)return 1;
    }

    Node *update(){
	size = (l?l->size:0) + (r?r->size:0) + 1;
	minimum = min(val, min((l?l->minimum:INF), (r?r->minimum:INF)));
	return this;
    }

    void rotate(){
	Node *par = p, *mid;
	if(par->l == this){
	    mid = r;r = par;
	    par->l = mid;
	}
	if(par->r == this){
	    mid = l;l = par;
	    par->r = mid;
	}
	if(mid)mid->p = par;
	p = par->p; par->p = this;
	if(p && p->l == par)p->l = this;
	if(p && p->r == par)p->r = this;
	par->update();
	update();
    }
    
    void spray(){
	while(state()){
	    int st = state() * p->state();
	    if(st == -1)rotate();
	    if(st == 1)p->rotate();
	    rotate();
	}
    }
};

typedef pair<Node*, Node*> NodeP;
typedef NodeP P;

Node* node(Node *r, int pos){
    int lsize = (r->l)?r->l->size:0;
    int rsize = (r->r)?r->r->size:0;
    if(lsize == pos - 1)return r;
    if(lsize >  pos - 1)return node(r->l, pos);
    if(lsize <  pos - 1)return node(r->r, pos - lsize - 1);
}

NodeP split(Node* r, int pos){
    if(pos == 0)return P(0, r);
    if(r->size == pos) return P(r, 0);
    r = node(r, pos);
    r->spray();
    Node *right = r->r;
    r->r = 0; right->p = 0;
    return P(r->update(), right->update());
}

Node *merge(Node *a, Node *b){
    if(a == 0)return b;
    if(b == 0)return a;
    a = node(a, a->size);
    a->spray();b->spray();
    a->r = b; b->p = a;
    a->update();
    return a->update();
}

NodeP delt(Node *r, int pos){
    NodeP tmp1 = split(r, pos);
    NodeP tmp2 = split(tmp1.second, 1);
    return P(merge(tmp1.first, tmp2.second), tmp2.first);
}

Node *insert(Node *r, Node *it, int pos){
    NodeP tmp = split(r, pos);
    return merge(merge(tmp.first, it), tmp.second);
}

Node *shift(Node *r, int left, int right){
    NodeP tmp = delt(r, right);
    return insert(tmp.first, tmp.second, left);
}

Node *setnum(Node *r, int pos, int val){
    r = node(r, pos + 1);
    r->spray();
    r->val = val;
    return r->update();
}

Node *comb(Node *r, Node *l){
    l->l = r;
    if(r) r->p = l;
    return l->update();
}

int main(){
    int n, q, a, x, y, z;
    cin >> n >> q;
    Node *r = 0;
    for(int i = 0;i < n;i++){
	cin >> a;
	r = comb(r, new Node(a));
    }
    for(int i = 0;i < q;i++){
	cin >> x >> y >> z;
	if(x == 0){
	    r = shift(r, y, z);
	}
	if(x == 1){
	    NodeP tmp1 = split(r, z + 1);
	    NodeP tmp2 = split(tmp1.first, y);
	    cout << tmp2.second->minimum << endl;
	    tmp1.first = merge(tmp2.first, tmp2.second);
	    r = merge(tmp1.first, tmp1.second);
	}
	if(x == 2){
	    r = setnum(r, y, z);
	}
    }
    return 0;
}
