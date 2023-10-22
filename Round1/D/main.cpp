#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
   vector<pair<int, int>> a;
   int n;
   vector<pair<pair<int, int>, pair<int, int>>>st; //tree--> <val, idx>
   vector<bool>lazy;
	public:
   SegmentTree(vector<int> &_a){
      this->n=_a.size();
      this->a.assign(n, {0,0});
      for(int i=0; i < n; i++){
	    a[i].first=_a[i];
	    a[i].second=(_a[i]*1000000006LL)%1000000007LL;
      }
      this->lazy.assign(4*n, false); //this is for either swapping or not..
      st.assign(4*n, {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}});
      build(1, 0, n-1);
   }
   pair<pair<int, int>, pair<int, int>> merge(pair<pair<int, int>, pair<int, int>> &seg1, pair<pair<int, int>, pair<int, int>> &seg2){
      if(seg2.first.first==INT_MAX)return seg1;
      if(seg1.first.first==INT_MAX)return seg2;
      pair<int, int> id1(INT_MAX, INT_MAX), id2(INT_MAX, INT_MAX);
      if(seg1.first.first>seg2.first.first) id1=seg1.first;
      else if(seg1.first.first<seg2.first.first) id1=seg2.first;
      else id1=min(seg1.first, seg2.first);

      if(seg1.second.first >seg2.second.first)id2=seg1.second;
      else if(seg1.second.first<seg2.second.first)id2=seg2.second;
      else id2=min(seg1.second, seg2.second);
      return {id1, id2};
   }
   void build(int id, int l, int r){
      if(l==r){
	st[id]={{a[l].first, l}, {a[r].second, r}};
	return;
      }
      int m=(l+r)/2;
      build(id*2, l, m);
      build(id*2+1, m+1, r);
      st[id]=merge(st[id*2], st[id*2+1]);
   }
   void update(int i, int j){
       this->update(1, 0, a.size()-1, i, j);
   }
   void propagate(int id, int l, int r){
      if(lazy[id]){
	swap(st[id].first, st[id].second);
	if(l!=r){
	   lazy[id*2]= !lazy[id*2];
	   lazy[id*2+1]= !lazy[id*2+1];
	}
	lazy[id]=false;
      }
      return;
   }
   void update(int id, int l, int r, int i, int j){
       propagate(id, l, r);
       cout <<st[id].first.first<<" "<<id<<endl;
       if(j<l || i>r)return;
       if( i<=l && j>=r){
	 lazy[id] = true;
         propagate(id, l, r);
	 return;
       }
       int m = (l+r)/2;
       update(id*2, l, m, i, j);
       update(id*2+1, m+1, r, i, j);
       st[id]=merge(st[id*2], st[id*2+1]);
   }
   int query(int i ,int j){
       return query(1, 0, a.size()-1, i, j).first.second+1;
   }
   pair<pair<int, int>, pair<int, int>> query(int id, int l, int r, int i, int j){
       propagate(id, l, r);
       if(j<l || i>r)return {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};
       if(i<=l && j>=r) return st[id];
       int m=(l+r)/2;
       auto seg1=query(id*2, l, m, i, j);
       auto seg2=query(id*2+1, m+1, r, i, j);
       return merge(seg1, seg2);
   }
};
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
      int N,Q;
      cin>>N;
      vector<int>a(N,0);
      for(int i = 0; i<N ;i++)cin>>a[i];
      SegmentTree st(a);
      cin>>Q;
      long long res=0;
      for(int q=0; q<Q;q++){
	 int l,r;
	 cin>>l>>r;
	 st.update(l-1, r-1);
	 res +=st.query(0, N-1);
	 cout<<res<<endl;
      }
	 return 0;
      cout <<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
