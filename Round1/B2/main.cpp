#include <bits/stdc++.h>
using namespace std;
vector<int>res;
bool bk(int id, vector<int> &items, vector<int> &current, long long P, int sum){
   if(sum<0)return false;
   if(current.size()>100)return false;
   if(P==1 && sum==0){
	 if(current.size() < res.size())res=current;
	 return true;
   }
   bool hassol=false;
   for(int i=id; i <items.size(); i++){
      if(P%items[i]!=0)continue;
      current.push_back(items[i]);
      hassol |= bk(i, items, current, P/items[i], sum-items[i]);
      current.pop_back();
   }
   return hassol;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
      long long P;
      cin>>P;
      res.assign(200, 1);
      vector<int> items;
      for(int i =1; i<=41; i++)
	 if(P%i==0)items.push_back(i);
      vector<int> current;
      auto hasSol = bk(0, items, current, P, 41);
      cout << "Case #"<<t<<":";
      if(!hasSol)cout <<" -1\n";
      else{
	  cout << " "<<res.size();
	  for(auto i:res)cout <<" "<<i;
	  cout<<endl;
      }
   }
}
