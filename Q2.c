#include<stdio.h>
struct node{
   int * data;
   int maxsize;
   int currsize;
   int front;
   int end;
   void (*constructor)(struct node *,int);
   void (*addElement)(struct node*,int ,int);
   void (*print)(struct node*);
   void (*deletedata)(struct node*,int);
};
void deletedata(struct node* p,int BorF){
   if(BorF==0){
      p->currsize--;
      p->front=(p->front+1)%p->maxsize;
   }
   if(BorF==1){
      p->currsize--;
      p->end=(p->end-1+p->maxsize)%p->maxsize;
   }
   if(p->currsize<p->maxsize/2){
         int *arr=(int*)malloc((p->maxsize/2)*sizeof(int));
         int k=0;
         for(int i=p->front;i!=p->end%p->maxsize;i=(i+1)%p->maxsize){
            arr[k++]=p->data[i];
         }
         arr[k]=p->data[p->end];
         p->front=0;
         p->end=k;
         free(p->data);
         p->data=arr;
         p->maxsize=p->maxsize/2;
   }
}
void print(struct node*p){
     for(int i=p->front;i!=(p->end+1)%p->maxsize;i=(i+1)%p->maxsize)
       printf("%d ",p->data[i]);
     printf("\n",p->maxsize);
}
void constructor(struct node* p,int size){
     p->data=(int*)malloc(size*sizeof(int));
     p->maxsize=size;
     p->currsize=0;
     p->front=0;
     p->end=-1+p->maxsize;
}
void addElement(struct node* p,int value,int BorF){
     if(BorF==0){
        p->currsize++;
        p->front=(p->front-1+p->maxsize)%p->maxsize;
        p->data[p->front]=value;
    }
    if(BorF==1){
       p->currsize++;
       p->end=(p->end+1)%p->maxsize;
       p->data[p->end]=value;
    }
    if(p->maxsize==p->currsize){
         int *arr=(int*)malloc(2*p->maxsize*sizeof(int));
         int k=0;
         for(int i=p->front;i!=p->end%p->maxsize;i=(i+1)%p->maxsize){
            arr[k++]=p->data[i];
         }
         arr[k]=p->data[p->end];
         p->front=0;
         p->end=k;
         free(p->data);
         p->data=arr;
         p->maxsize=2*p->maxsize;
     }
}
int main(){
   struct node * p=(struct node *)malloc(sizeof(struct node));
   int n;
   printf("SIZE:");
   scanf("%d", &n);
   p->constructor=constructor;
   p->addElement=addElement;
   p->print=print;
   p->deletedata=deletedata;
   p->constructor(p,n);
   int choice;
   printf("Enter Choice :\n");
   printf("1. ADD ELEMENT :\n");
   printf("2. DELETE ELEMENT :\n");
   printf("3. PRINT :\n");
   printf("-1.EXIT :\n");
   scanf("%d",&choice);
   while(choice!=-1){
      if(choice==1){
          printf("   1.ADD AT LAST :\n");
          printf("   2.ADD AT FRONT :\n");
          printf("   ");
          int choice2;
          scanf("%d",&choice2);
          int value;
          printf("       VALUE :\n");
          printf("       ");
          scanf("%d",&value);
          if(choice2==1){
              p->addElement(p,value,0);
          }
          if(choice2==2){
              p->addElement(p,value,1);
          }
      }
      if(choice==2){
         if(p->currsize==0){
           printf("NO NODE TO DELETE\n");
         }
          if(p->currsize!=0){
          printf("   1.DELETE AT LAST :\n");
          printf("   2.DELETE AT FRONT :\n");
          printf("   ");
          int choice2;
          scanf("%d",&choice2);
          if(choice2==1){
              if(p->currsize!=0)
              p->deletedata(p,0);
          }
          if(choice2==2){
             if(p->currsize!=0)
              p->deletedata(p,1);
          }
          }
      }
      if(choice==3){
         p->print(p);
      }
      printf("Enter Choice :\n");
      printf("1. ADD ELEMENT :\n");
      printf("2. DELETE ELEMENT :\n");
      printf("3. PRINT :\n");
      printf("-1.EXIT :\n");
      scanf("%u",&choice);
   }
   return 0;
}
