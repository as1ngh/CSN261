#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
       int n;
       cin>>n;
       map<int,vector<ll>>map;
       ll x=0;
       map[0].push_back(0);
       for(ll i=1;i<=n;i++){
            ll a;
            cin>>a;
            x=x^a;
            map[x].push_back(i);
       }
       ll ans=0;
       set<pair<int,pair<int,int>>>myset;
       for(auto it=map.begin();it!=map.end();it++){
          for(int i=0;i<(it->second).size();i++){
             for(int j=i+1;j<(it->second).size();j++){
                 int end=(it->second).at(j);
                 int start=(it->second).at(i)+1;
                 for(int l=start+1;l<=end;l++){
                    pair<int,int>temp=make_pair(l,end);
                    pair<int,pair<int,int>>temp2=make_pair(start,temp);
                    //cout<<start<<" "<<l<<" "<<end<<endl;
                    myset.insert(temp2);
                    ans++;
                 }
               }
          }
       }
       for(auto it =myset.begin();it!=myset.end();it++){
          cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<endl;
       }
       cout<<ans<<endl;
}
