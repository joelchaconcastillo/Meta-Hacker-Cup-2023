#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
      int N, Q;
      string st;
      cin>>N>>st>>Q;
      vector<int> count(N+1,0), s(N+1, 0);
      for(int i = 1 ; i <= N; i++)s[i] = st[i-1]-'0';
      for(int i=0; i < Q; i++){
	 int p;
	 cin>>p;
	 count[p]++;
	 count[p]%=2;
      }
      for(int i=1; i <=N;i++){
	     if(count[i]==0) continue;
	     for(int j=i; j <= N; j+=i){
		 s[j] ^=1;
	     }
      }
      int res=0;
      for(int i=1; i <= N; i++){
	 if(s[i]==0)continue;
	 res++;
	 for(int j=i; j<=N; j+=i)s[j] ^=1;
      }
      cout <<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
