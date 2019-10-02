#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a1,b1,c1,d1,e1;
    int a2,b2,c2,d2,e2;
    cin>>a1>>b1>>c1>>d1;
    cin>>a2>>b2>>c2>>d2;
    vector<int>ans;
    ans.push_back(a2*a1);
    ans.push_back(a2*b1+a1*b2);
    ans.push_back(a2*c1+a1*c2+b2*b1);
    ans.push_back(a2*d1+a1*d2+b2*c1+b1*c2);
    ans.push_back(c2*c1+b2*d1+b1*d2);
    ans.push_back(c2*d1+c1*d2);
    ans.push_back(d1*d2);
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }


	return 0;
}