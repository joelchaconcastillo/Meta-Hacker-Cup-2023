#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      int N, Q; string st;
      cin>>N>>st>>Q;
      vector<int> press(N+1, 0);
      int res = 0;
      for(int i = 1 ; i <= N; i++){
	 if(st[i-1]=='0')continue;
	 res++;
	 for(int j = i; j <=N; j+=i) st[j-1] ^= '0'^'1';
	 press[i] = '1';
      }
      cout <<"Case #"<<t<<":";
      long long count = 0;
      for(int i = 0 ; i < Q; i++){
	  int q;
	  cin>>q;
	  res -=press[q];
	  press[q] ^=1;
	  res +=press[q];
	  count +=res;
      }
      cout <<" "<<count<<endl;
   }
   return 0;
}
