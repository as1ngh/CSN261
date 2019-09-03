#include<bits/stdc++.h>
using namespace std;
int a[1000]={0};
map<int,int>mymap;
int main(){
   int N;
   cin>>N;
   for(int i=1;i<=N;i++)
     cin>>a[i];
   int n;
   cin>>n;
   mymap[0]=0;
   for(int i=1;i<=N;i++){
      mymap[i]=mymap[i-1]+a[i];
   }
   int maxlen=INT_MIN;
   pair<int,int>indexes;
   for(int i=0;i<=N;i++){
     for(int j=i+1;j<=N;j++){
        if((mymap[j]-mymap[i])==n){
          if((j-i)>maxlen){
            maxlen=(j-i);
            indexes.first=i;
            indexes.second=j-1;
          }
        }
     }
   }
   if(maxlen==INT_MIN){
      cout<<"NOT FOUND"<<endl;
   }
   else{
      cout<<"FIRST:"<<indexes.first<<endl;
      cout<<"SECOND:"<<indexes.second<<endl;
      cout<<"LENGTH:"<<indexes.second-indexes.first+1<<endl;
   }
}
