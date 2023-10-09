#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, bool> memoP, memoS;
long long memo[100][100];
vector<long long> sol;
int helper(vector<long long> &factors, int item, long long cP, long long cS, vector<long long> &res){
	if(res.size()> 100)return INT_MAX;
	if(cS < 0)return INT_MAX;
//	if(memo[item][cS]!=0)return memo[item][cS];
	if(cP==1 && cS==0){
		   if(res.size() < sol.size()) sol=res;
		   return res.size();
	}
	int count = INT_MAX;
	for(int i = item; i < factors.size(); i++){
	   if(cP%factors[i]!=0)continue;
	   if(cS-factors[i]<0)continue;
	   res.push_back(factors[i]);
	   int current = helper(factors, i, cP/factors[i], cS-factors[i], res);
	   count = min(current, count);
	   res.pop_back();
	}
	return memo[item][cS]=count;
}
vector<long long> primes;
void compute_primes(long long n){
   vector<bool> isprime(n+1, true);
   isprime[0]=isprime[1]=false;
   for(int i =2 ; i*i <= n; i++){
       if(!isprime[i])continue;
       for(int j = i*i; j<=n; j+=i)isprime[j]=false;
       primes.push_back(i);
   }
}
vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
	bool check=false;
	long long cu=d;
        while (n % d == 0) {
//		if(!check){
//		   check=true;
            	   factorization.push_back(cu);
           // 	   factorization.push_back(n);
//		}
	    cu*=d;
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   compute_primes(1e6);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	   long long P;
	   memset(memo, 0, sizeof memo);
	   cin>>P;
	   auto factors = trial_division4(P);
	   vector<long long>res; // factors;
	   sol.assign(200, 1);
	   factors.push_back(1);
	   helper(factors, 0, P, 41, res);
	   cout <<"Case #"<<t<<":";
	   if(sol.size()>100) cout <<" "<<-1 <<endl;
	   else{
		   cout<<" "<<sol.size();
		   for(auto i:sol) cout<<" "<<i;
		   cout<<endl;
	   }
   }
   return 0;
}
