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
    int n1;
    int n2;
    cin>>n1;
    int a[1000]={0};
    int b[1000]={0};
    int c[2000]={0};
    for(int i=n1-1;i>=0;i--){
        cin>>a[i];
    }
    cin>>n2;
    for(int i=n2-1;i>=0;i--){
        cin>>b[i];
    }
    int choice;
    cin>>choice;
    if(choice==1){
        for(int i=max(n1,n2)-1;i>=0;i--){
            cout<<i<<"-->"<<a[i]+b[i]<<endl;
        }
    }
    else{
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                c[i+j]+=a[i]*b[j];
            }
        }
        for(int i=n1-1+n2-1;i>=0;i--){
            cout<<i<<"-->"<<c[i]<<endl;
        }
    }
	return 0;
}
