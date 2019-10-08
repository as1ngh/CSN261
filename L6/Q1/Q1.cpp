#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

struct node{
   int a;
   int b[100];
   int size=0;
};
void dfs(node graph[],bool vis[],int curr){
   if(vis[curr]){
      return;
   }
   cout<<(char)(curr+'A')<<" ";
   vis[curr]=true;
   for(int i=0;i<graph[curr].size;i++){
     if(!vis[graph[curr].b[i]]){
        dfs(graph,vis,graph[curr].b[i]);
     }
   }
}

void bfs(node graph[],bool vis[]){
    int l=0;
    int r=1;
    int size=1;
    int curr[1000]={0};
    vis[0]=true;
    while(size!=0){
       for(int i=0;i<graph[curr[l]].size;i++){
          if(!vis[graph[curr[l]].b[i]]){
           vis[graph[curr[l]].b[i]]=true;
           curr[r++]=graph[curr[l]].b[i];
           size++;
          }
       }
       cout<<(char)(curr[l++]+'A')<<" ";
       size--;
    }
}

bool cycle(node graph[]){
   int vertices=0;
   int edges=0;
   for(int i=0;i<100;i++){
       if(graph[i].size){
          vertices++;
          edges+=graph[i].size;
       }
   }
   edges/=2;
   if(edges>vertices-1){
     return true;
   }
   return false;
}
void diadfs(node graph[],int curr,int dis[100],int d){
    if(dis[curr]<=d){
      return;
    }
    dis[curr]=d;
    for(int i=0;i<graph[curr].size;i++){
         diadfs(graph,graph[curr].b[i],dis,d+1);
    }
}

int main(){
    cout<<"1. Inset edge\n2. BFS traversal\n3. DFS traversal\n4. Cycle finding in the graph\n5. Calculate diameter of the graph\n";
    int choice;
    cin>>choice;
    node graph[100];
    while(choice!=-1){
       if(choice==1){
          char aa,bb;
          cout<<"ENTER VERTICES:\n";
          cin>>aa>>bb;
          int x=aa-'A';
          int y=bb-'A';
          graph[x].b[graph[x].size]=y;
          graph[x].size++;
          graph[y].b[graph[y].size]=x;
          graph[y].size++;
       }
       else if(choice==2){
          bool vis[100]={0};
          bfs(graph,vis);
          cout<<"\n";
       }
       else if(choice==3){
          bool vis[100]={0};
          dfs(graph,vis,0);
          cout<<"\n";
       }
       else if(choice==4){
         bool check=cycle(graph);
         if(check){
           cout<<"YES\n";
         }
         else{
           cout<<"NO\n";
         }
       }
       else if(choice==5){
            int diameter=0;
            int dis[100];
            for(int i=0;i<100;i++){
               if(graph[i].size!=0){
                  memset(dis,1000000,sizeof(dis));
                  diadfs(graph,i,dis,0);
                  for(int i=0;i<100;i++){
                    if(graph[i].size!=0){
                      if(dis[i]>diameter){
                         diameter=dis[i];
                      }
                    }
                  }
               }
            }
            cout<<diameter<<endl;
       }
       cout<<"1. Inset edge\n2. BFS traversal\n3. DFS traversal\n4. Cycle finding in the graph\n5. Calculate diameter of the graph\n";
       cin>>choice;
    }
	return 0;
}
/*
1 AD
1 AB
1 BE
1 BC
1 EC
1 CF
1 CG
*/
