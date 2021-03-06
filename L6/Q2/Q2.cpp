#include<bits/stdc++.h>
using namespace std;

struct node{
   node*children[10000];
   int size;
   int data;
};
struct tree{
   node *root;
   int size;
};
void build(tree t[],int n){
    int stack[1000]={0};
    stack[0]=0;
    int l=0,r=1;
    stack[0]=0;
    for(int i=1;i<=n;i++){
        stack[r++]=i;
        while(r>=2&&t[stack[r-1]].size==t[stack[r-2]].size){
           if(t[stack[r-1]].root->data<=t[stack[r-2]].root->data){
                  (t[stack[r-1]].root)->children[(t[stack[r-1]].root)->size]=t[stack[r-2]].root;
                  (t[stack[r-1]].root)->size++;
                  t[stack[r-2]].root=0;
                  t[stack[r-1]].size+=t[stack[r-2]].size;
                  t[stack[r-2]].size=0;
                  t[stack[r-2]].size=t[stack[r-1]].size;
                  t[stack[r-2]].root=t[stack[r-1]].root;
                  t[stack[r-1]].root=0;
                  t[stack[r-1]].size=0;
                  r--;
           }
           else if(t[stack[r-1]].root->data>t[stack[r-2]].root->data){
                  (t[stack[r-2]].root)->children[(t[stack[r-2]].root)->size]=t[stack[r-1]].root;
                  (t[stack[r-2]].root)->size++;
                  t[stack[r-1]].root=0;
                  t[stack[r-2]].size+=t[stack[r-1]].size;
                  t[stack[r-1]].size=0;
                  stack[r-2]=stack[r-2];
                  r--;
           }
           //cout<<t[stack[r-1]].size<<"--->>";
        }
    }
}

ofstream file;

void print(node*root,int prev){
  if(!root){
    return;
  }
  if(prev!=-1)
  file<<"   "<<prev<<"--"<<root->data<<endl;
  for(int i=0;i<root->size;i++){
      print(root->children[i],root->data);
  }
}

void prin(node*root){
  if(!root)
    return;
  cout<<root->data<<" ";
  for(int i=0;i<root->size;i++){
     prin(root->children[i]);
  }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    //sort(a,a+n);
    tree t[n];
    for(int i=0;i<n;i++){
       node* nn=new node();
       nn->data=a[i];
       nn->size=0;
       t[i].root=nn;
       t[i].size=1;
    }
    build(t,n);
    file.open("Q2.dot");

    if(file.is_open())
    {
        file << "graph MST { " << endl;
        file << "   graph [ dpi = 1200 ] ; " << endl;
    }
    for(int i=0;i<n;i++){
      if(t[i].size==1){
        file<<"   "<<t[i].root->data<<endl;
      }
      if(t[i].root){
        prin(t[i].root);
        print(t[i].root,-1);
        //cout<<t[i].size<<"---->"<<i;
        cout<<endl;
      }
    }
    file<<"}";
}
