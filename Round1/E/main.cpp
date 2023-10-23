#include <bits/stdc++.h>
using namespace std;
int S; //block size
struct Query{
   int l, r, k;
   bool operator<(Query &other)const{
	return make_pair(l/S, r) < make_pair(other.l/S, other.r);
   }
};
vector<string> W;
map<string, int>rollHash;
void add(int idx){
   string c="";
   for(auto i:W[idx]) c+=i, rollHash[c]++;
}
void remove(int idx){
   string c="";
   for(auto i:W[idx]) c+=i, rollHash[c]--;
}
int ans(int k){
   
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      int N;
      cin>>N;
      S = sqrt(N)+1;
      W.assign(N, "");
      for(int i = 0 ; i < N ; i++){
	      cin>>W[i];
	      reverse(W[i].begin(), W[i].end());
      }
      int Q;
      cin>>Q;
      vector<Query> queries(Q);
      for(int i = 0 ; i < Q; i++){
	 cin>>queries[i].l>>queries[i].r>>queries[i].k;
	 queries[i].l--; queries[i].r--;
      }
      sort(queries.begin(), queries.end());
      int res=0, l=0, r=-1;
      for(auto &q:queries){
	 while(l < q.l) remove(l++);
	 while(l > q.l) add(--l);
	 while(r < q.r) add(++r);
	 while(r > q.r) remove(r--);
	 res += ans();
      }
      cout <<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
