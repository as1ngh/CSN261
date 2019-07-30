#include<stdio.h>
FILE * file;
int occupied[300]={0};
struct node{
   int roll;
   char name[100];
   char DOB[20];
   char address[200];
   long long int phone;
   struct node*left;
   struct node*right;
};
struct queue{
   struct node*head;
   struct node*tail;
   int size;
   void (*constructor)(struct queue*);
   void (*addnode)(struct queue*);
   void (*print)(struct queue*);
   void (*insert)(struct queue*);
   void (*del)(struct queue*,int*);
   struct node*(*search)(struct queue*,int *);
   void (*modify)(struct queue*,int*);
   void (*sort)(struct queue*);
};
void constructor(struct queue *q){
   q->head=0;
   q->tail=0;
   q->size=0;
}
void addnode(struct queue*q){
  while(!feof(file)){
     struct node *temp=(struct node*)malloc(sizeof(struct node));
     fscanf(file,"%d;%[^;];%[^;];%[^;];%lld\n",&temp->roll,temp->name,temp->DOB,temp->address,&(temp->phone));
     occupied[temp->roll]=1;
     temp->roll+=100;
     if(q->size==0){
        q->head=temp;
        q->tail=q->head;
     }
     else{
       q->tail->right=temp;
       temp->left=q->tail;
       q->tail=q->tail->right;
     }
     q->size++;
  }
  q->tail->right=q->head;
  q->head->left=q->tail;
}
void print(struct queue* q){
  struct node*temp=q->head;
  for(int i=0;i<q->size;i++){
     printf("ROLL NO:%d\n",temp->roll);
     printf("NAME:%s\n",temp->name);
     printf("DOB:%s\n",temp->DOB);
     printf("ADDRESS:%s\n",temp->address);
     printf("PHONE NO:%lld\n\n",temp->phone);
     temp=temp->right;
  }
}
void insert(struct queue*q){
   for(int i=1;i<300;i++){
      if(occupied[i]==0){
         occupied[i]=1;
         struct node *temp=(struct node*)malloc(sizeof(struct node));
         temp->roll=i+100;
         printf(" ENTER NAME:");
         gets();
         gets(temp->name);
         printf("ENTER DOB:");
         gets(temp->DOB);
         printf("ENTER ADDRESS:");
         gets(temp->address);
         printf("ENTER PHONE NO:");
         scanf("%lld",&temp->phone);
         q->tail->right=temp;
         temp->left=q->tail;
         temp->right=q->head;
         q->head->left=temp;
         q->tail=q->tail->right;
         q->size++;
         return;
      }
   }
}
void del(struct queue*q,int roll){
   struct node *temp=q->head;
   occupied[roll-100]=0;
   for(int i=0;i<q->size;i++){
      if(temp->roll==roll){
         if(temp==q->head)
           q->head=q->head->right;
         if(temp==q->tail)
           q->tail=q->tail->left;
         struct node*l=temp->left;
         struct node*r=temp->right;
         temp->left=0;
         temp->right=0;
         l->right=r;
         r->left=l;
         q->size--;
         free(temp);
         return;
      }
      temp=temp->right;
   }
}
struct node* search(struct queue * q,int roll){
    struct node *temp=q->head;
    for(int i=0;i<q->size;i++){
      if(temp->roll==roll){
         return temp;
      }
      temp=temp->right;
    }
    return NULL;
}
void modify(struct queue*q,int roll){
   struct node *temp=q->head;
    for(int i=0;i<q->size;i++){
      if(temp->roll==roll){
         printf(" ENTER NAME:");
         gets();
         gets(temp->name);
         printf("ENTER DOB:");
         gets(temp->DOB);
         printf("ENTER ADDRESS:");
         gets(temp->address);
         printf("ENTER PHONE NO:");
         scanf("%lld",&temp->phone);
         return;
      }
      temp=temp->right;
    }
    printf("NO NODE FOUND\n");
    return ;
}
void swap(struct node*aa,struct node*bb){
    struct node*l=aa->left;
    struct node*r=bb->right;
    l->right=bb;
    bb->left=l;
    aa->right=r;
    r->left=aa;
    bb->right=aa;
    aa->left=bb;
    return ;
}
void sort(struct queue *q){
    for(int i=0;i<q->size;i++){
      struct node*temp=q->head;
      for(int j=0;j<q->size-1-i;j++){
         if(strcmp(temp->name,temp->right->name)>0){
            if(q->head==temp)
              q->head=q->head->right;
            if(temp->right==q->tail)
              q->tail=q->tail->left;

            swap(temp,temp->right);
         }
         else
          temp=temp->right;
      }
    }
}
void init(){
   file=fopen("StudentData.csv","r");
   fscanf(file,"S.No.;Name;D.O.B.;Address;Phone No\n");
}
// sort
int main(){
     init();
     struct queue*q=(struct queue*)malloc(sizeof(struct queue));
     q->constructor=q->constructor;
     q->addnode=addnode;
     q->print=print;
     q->insert=insert;
     q->del=del;
     q->search=search;
     q->modify=modify;
     q->sort=sort;
     q->addnode(q);
     int choice;
     printf("1:PRINT\n2:INSERTION:\n3:DELETION:\n4:SEARCH:\n5:MODIFY:\n6:SORT\n-1:EXIT:\n");
     scanf("%d",&choice);
     while(choice!=-1){
         if(choice==1)
           q->print(q);
         if(choice==2)
           q->insert(q);
         else if(choice==3){
           if(q->size==0){
              printf("NO NODE TO DELETE\n");
           }
            if(q->size!=0){
              printf("ENTER ROLL NO. TO DELETE:");
              int roll;
              scanf("%d",&roll);
              q->del(q,roll);
            }
         }
         else if(choice==4){
            if(q->size==0){
               printf("NO ELEMENT TO SEARCH\n");
            }
            else{
              printf("ENTER ROLL NO. TO SEARCH:");
              int roll;
              scanf("%d",&roll);
              struct node*n=q->search(q,roll);
              if(n!=NULL){
                  printf("ROLL NO:%d\n",n->roll);
                  printf("NAME:%s\n",n->name);
                  printf("DOB:%s\n",n->DOB);
                  printf("ADDRESS:%s\n",n->address);
                  printf("PHONE NO:%lld\n\n",n->phone);
              }
              else if(n==NULL){
                printf("NO NODE FOUND\n");
              }
            }
         }
         else if(choice==5){
               int roll;
               printf("ENTER ROLL NO. TO MODIFY:");
               scanf("%d",&roll);
               q->modify(q,roll);
         }
         else if(choice==6){
              q->sort(q);
         }
         printf("1:PRINT\n2:INSERTION:\n3:DELETION:\n4:SEARCH:\n5:MODIFY:\n6:SORT\n-1:EXIT:\n");
         scanf("%d",&choice);
     }
}
