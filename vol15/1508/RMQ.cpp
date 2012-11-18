#include<iostream>
#include<cstdlib>
#include<ctime>
#include<ctime>
#include<map>
using namespace std;

#define INF (1 << 30)

struct treap_n{
  int value, pri, minimum, count;
  treap_n* right, *left;
  treap_n(int v){
    value = v;
    pri = rand() % INF;
    count = 1;
    minimum = v;
    right = left = 0;
  }
};

int node_count(const treap_n* r){
  if(r == 0)return 0;
  return r -> count;
}


int node_min(const treap_n* r){
  if(r == 0)return INF;
  return r -> minimum;
}

treap_n* update(treap_n* r){
  r -> count = node_count(r -> left) + node_count(r -> right) + 1;
  r -> minimum = min(node_min(r -> left), node_min(r -> right));
  r -> minimum = min(r -> minimum, r -> value);
  return r;
}

treap_n* merge(treap_n* a, treap_n *b){
  if(a == 0)return update(b);
  if(b == 0)return update(a);
  if(a -> pri > b -> pri){
    treap_n* tmp = a -> right;
    a -> right = merge(tmp, b);
    return update(a);
  }
  else{
    treap_n* tmp = b -> left;
    b -> left = merge(a, tmp);
    return update(b);
  }
}

pair<treap_n*, treap_n*> split(treap_n* r,int pos){
  if(r == 0) return make_pair((treap_n*)0, (treap_n*)0);
  int left_count = node_count(r -> left);
  if(pos > left_count){
    pair<treap_n*, treap_n*> tmp;
    tmp = split(r -> right, pos - left_count - 1);
    r -> right = tmp.first;
    return make_pair(update(r), tmp.second);
  }
  else{
    pair<treap_n*, treap_n*> tmp;
    tmp = split(r -> left, pos);
    r -> left = tmp.second;
    return make_pair(tmp.first, update(r));
  }
}

treap_n* insert(treap_n* r, int pos, treap_n* n){
  pair<treap_n*, treap_n*>tmp;
  tmp = split(r, pos - 1);
  r = merge(tmp.first, n);
  r = merge(r, tmp.second);
  return r;
}

treap_n* remove(treap_n* r,int pos){
  pair<treap_n*, treap_n*>tmp;
  tmp = split(r, pos - 1);
  r = merge(tmp.first, split(tmp.second, 1).second);
  return r;
} 

treap_n* node(treap_n* r, int pos){
  int left_count = node_count(r -> left);
  if(pos == left_count + 1){
    return r;
  }
  if(pos > left_count){
    return node(r -> right, pos - left_count - 1);
  }
  else{
    return node(r -> left, pos);
  }
}

treap_n* shift(treap_n* r, int left, int right){
  treap_n* tmp = node(r, right);
  r = remove(r, right);
  r = insert(r, left, tmp);
  return r;
}

int minimum(treap_n* r, int left, int right){
  pair<treap_n*, treap_n*> tmp1, tmp2 ;
  int res;
  tmp1 = split(r, left - 1);
  tmp2 = split(tmp1.second , right - left + 1);
  res = node_min(tmp2.first);
  r = merge(tmp1.first, merge(tmp2.first, tmp2.second));
  return res;
}

treap_n* change(treap_n* r, int pos, int val){
  r = remove(r, pos);
  r = insert(r, pos, new treap_n(val));
  return r;
}



int main(){
  int tmp, n, q, x, y, z;
  srand((unsigned int)time(0));
  cin >> n >> q;
  cin >> tmp;
  treap_n root(tmp);
  treap_n* r = &root;
  for(int i = 2;i <= n;i++){
    cin >> tmp;
    r = insert(r, i, new treap_n(tmp));
  }
  for(int i = 0;i < q;i++){
    cin >> x >> y >> z;
    if(x == 0){
      r = shift(r, y + 1, z + 1);
    }
    if(x == 1){
      cout << minimum(r, y + 1, z + 1) << endl;
    }
    if(x == 2){
      r = change(r, y + 1, z);
    }
  }
  return 0;
}


