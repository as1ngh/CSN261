#include<stdio.h>
FILE * file;
FILE *file2;
int ** arr;
int getn(){
    int n=0;
    int temp;
    fscanf(file,"%d",&temp);
    n++;
    char ch;
    fscanf(file,"%c",&ch);
    while(ch!='\n'){
       fscanf(file,"%d",&temp);
       n++;
       fscanf(file,"%c",&ch);
    }
    return n;
}
int get2(int n){
  int temp;
  for(int i=0;i<32;i++){
      if((1<<i)&n)
         temp=i;
  }
  int ans=1<<(temp+1);
  return ans;
}
int curr=0;
int n;
int max;
void dfs(int x1,int y1,int x2,int y2,int **arr,int lev){
    int one=0,zero=0;
    for(int i=x1;i<x2;i++){
       for(int j=y1;j<y2;j++){
          if(arr[i][j]==1)
            one++;
          if(arr[i][j]==0)
            zero++;
       }
    }
    if(zero!=0&&one!=0){
          int xmid=(x1+x2)/2;
          int ymid=(y1+y2)/2;
          dfs(x1,y1,xmid,ymid,arr,lev+1);
          dfs(x1,ymid,xmid,y2,arr,lev+1);
          dfs(xmid,y1,x2,ymid,arr,lev+1);
          dfs(xmid,ymid,x2,y2,arr,lev+1);
          return;
    }
    else{
      curr=curr+1;
      for(int i=x1;i<x2;i++){
         for(int j=y1;j<y2;j++){
            arr[i][j]=curr;
         }
      }
      if(one!=0){
         printf("(%d, 1, %d)\n",curr,lev);
      }
      else{
        printf("(%d, 0, %d)\n",curr,lev);
      }
    }
}
int main(){
   file=fopen("L2_P2_inputsample.txt","r");
   file2=fopen("L2_P2_inputsample.txt","r");
   n=getn();
   max=get2(n);
   arr=(int**)malloc(max*sizeof(int*));
   for(int i=0;i<max;i++){
      arr[i]=(int*)malloc(max*sizeof(int));
   }
   fseek(file, 0, SEEK_SET);
   //memset(arr,0,sizeof(arr));
   int i=max-n;
   int j=max-n;
   while(!feof(file)){
        int t;
        char ch;
        fscanf(file,"%d",&t);
        fscanf(file,"%c",&ch);
        arr[i][j]=t;
        if(j==max-1){
           j=max-n;
           i++;
        }
        else{
          j++;
        }
        if(i==max)
          break;
   }
   dfs(0,0,max,max,arr,1);
   for(int i=0;i<max;i++){
     for(int j=0;j<max;j++)
       printf("%d\t",(*(*(arr+i)+j)));
     printf("\n");
   }
}
