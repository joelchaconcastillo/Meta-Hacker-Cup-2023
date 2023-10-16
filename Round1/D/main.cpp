#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
   vector<pair<int, int>> a;
   int n;
   vector<pair<int, int>>st; 
	public:
   SegmentTree(vector<int> &_a){
      this->n=_a.size();
      this->a.assign(n, {0,0});
      for(int i=0; i < n; i++){
	    a[i].first=_a[i];
	    a[i].second=(_a[i]*1000000006LL)%1000000007LL;
      }
      st.assign(4*n+1, {INT_MAX, INT_MAX});
      build(1, 0, n-1);
   }
   pair<int, int> merge(pair<int, int> &seg1, pair<int, int> &seg2){
      if(seg2.first==INT_MAX)return seg1;
      if(seg1.first==INT_MAX)return seg2;
      int id1=INT_MAX, id2=INT_MAX;
      if(a[seg1.first].first>a[seg2.first].first) id1=seg1.first;
      else if(a[seg1.first].first<a[seg2.first].first) id1=seg2.first;
      else id1=min(seg1.first, seg2.first);

      if(a[seg1.second].second>a[seg2.second].second)id2=seg1.second;
      else if(a[seg1.second].second<a[seg2.second].second)id2=seg2.second;
      else id2=min(seg1.second, seg2.second);
      return {id1, id2};
   }
   pair<int, int> build(int id, int l, int r){
      if(l==r){
	return st[id]={l, r};
      }
      int m=(l+r)/2;
      auto seg1 = build(id*2, l, m);
      auto seg2 = build(id*2+1, m+1, r);
      return st[id]=merge(seg1, seg2);
   }
   void update(int i, int j){
       this->update(1, 0, a.size()-1, i, j);
   }
   void update(int id, int l, int r, int i, int j){
       if(j<l || i>r)return;
       if(l==r){
       	    swap(st[id].first, st[id].second);
       	    swap(a[l].first, a[r].second);
	    return;
       }
       int m = (l+r)/2;
       update(id*2, l, m, i, j);
       update(id*2+1, m+1, r, i, j);
       st[id]=merge(st[id*2], st[id*2+1]);
   }

//   void update(int id, int l, int r, int i, int j){
//       if(j<l || i>r)return ;//{INT_MAX, INT_MAX};
//       if(l==r){
//       	    swap(a[l].first, a[r].second);
//	    return;
//       }
//       int m = (l+r)/2;
//       update(id*2, l, m, i, j);
//       update(id*2+1, m+1, r, i, j);
//       st[id]=merge(st[id*2], st[id*2+1]);
//   }
   int query(int i ,int j){
//	   cout<<"---> ";
//	   for(auto i:a)cout <<i.first<<" ";
//	   cout<<endl;
       auto v = query(1, 0, a.size()-1, i, j).first+1;
 //      cout<<v<<endl;
       return v;
   }
   pair<int, int> query(int id, int l, int r, int i, int j){
       if(j<l || i>r)return {INT_MAX, INT_MAX};
       if(i>=l && j<=r) return st[id];
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
//      cout <<st.query(0, a.size()-1)<<endl;
      for(int q=0; q<Q;q++){
	 int l,r;
	 cin>>l>>r;
	 st.update(l-1, r-1);
//	 cout <<st.query(l-1, r-1)<<endl;
	 res +=st.query(l-1, r-1);
      }
      cout <<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
