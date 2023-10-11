#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      long long n, sum=0;
      vector<int> res;
cin>>n;
for(int i=2; i*i<=n; i++){
	 while(n%i==0){
	    res.push_back(i);
	    sum +=i;
	    n/=i;
	 }
      } 
      if(n!=1) sum+=n, res.push_back(n);
      cout<<"Case #"<<t<<":";
      if(sum>41)cout <<" -1\n";
      else{
          //expand 1's if its necessary
          while(sum<41)res.push_back(1), sum++;
	  cout <<" "<<res.size();
          for(auto i:res)cout <<" "<<i;
          cout<<endl;
      }
   }
   return 0;
}
