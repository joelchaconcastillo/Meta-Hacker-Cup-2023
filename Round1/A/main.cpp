#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
     int N;
     cin>>N;
     vector<double> points(N);
     for(int i = 0 ; i < N; i++){
	     cin>>points[i];
     }
    sort(points.begin(), points.end());
     double res = 0;
     if( N == 5){
	 auto res1 = (points[N-1]+points[N-3]-points[0]-points[1])/2.0;
	 auto res2 = (points[N-1]+points[N-2]-points[0]-points[2])/2.0;
	 res = max(res1, res2);
     }else{
	 res = (points[N-1]+points[N-2])/2.0 - (points[0]+points[1])/2.0;
     }
//     double res = 0.0;
//     for(int i = 1; i+2<N; i++){
//	     double left = (points.front()+points[i])/2.0;
//	     double right = (points.back()+points[i+1])/2.0;
//	     res= max(res, right-left);
//     }
     cout <<"Case #"<<t<<": "<< res<<endl;
   }
   return 0;
}
