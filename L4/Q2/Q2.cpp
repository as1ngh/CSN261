#include<bits/stdc++.h>
using namespace std;
int a[100][100]={0};
int counter=0;
bool checker(int x,int y,int n){
   for(int i=1;i<=y;i++){
     if(a[x][i]==1)
       return false;
   }
   for(int i=x,j=y;i>0&&j>0;i--,j--){
      if(a[i][j]==1)
        return false;
   }
   for(int i=x,j=y;i<=n&&j>0;i++,j--){
      if(a[i][j]==1)
        return false;
   }
   return true;
}
void build(int n,int x,int y){
   if(y==n+1){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
          cout<<a[i][j]<<" ";
        cout<<endl;
      }
      cout<<endl;
      counter++;
      return;
   }
   for(int i=1;i<=n;i++){
     if(checker(i,y,n)==true){
       a[i][y]=1;
       build(n,0,y+1);
       a[i][y]=0;
     }
   }
}
int main(){
   int n;
   cin>>n;
   build(n,1,1);
   cout<<"POSSIBLE COMBINATIONS->"<<counter;
}
