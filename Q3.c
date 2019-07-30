#include<stdio.h>
int red[2000][2000];
int green[2000][2000];
int blue[2000][2000];
void assignvalueinit(){
   for(int i=0;i<2000;i++){
     for(int j=0;j<2000;j++){
       red[i][j]=-1;
       green[i][j]=-1;
       blue[i][j]=-1;
     }
   }
}
void assignvalue(){
    FILE * fBlue;
    FILE * fGreen;
    FILE * fRed;
    fBlue=fopen("Q3_ip_Blue.dat","r");
    fRed=fopen("Q3_ip_Red.dat","r");
    fGreen=fopen("Q3_ip_Green.dat","r");
    int valueRed;
    int valueGreen;
    int valueBlue;
    fscanf(fBlue,"%d",&valueBlue);
    fscanf(fGreen,"%d",&valueGreen);
    fscanf(fRed,"%d",&valueRed);
    int i=0,j=0;
    while(!feof(fBlue)&&!feof(fRed)&&!feof(fGreen)){
        red[i][j]=valueRed;
        green[i][j]=valueGreen;
        blue[i][j]=valueBlue;
        char cr;
        char cb;
        char cg;
        fscanf(fRed,"%c",&cr);
        fscanf(fBlue,"%c",&cb);
        fscanf(fGreen,"%c",&cg);
        if(cr=='\n'&&cb=='\n'&&cg=='\n'){
           i++;
           j=0;
        }
        else if(cr==','&&cb==','&&cg==','){
           j++;
        }
        else{
          printf("WRONG FORMAT");
          return;
        }
       fscanf(fBlue,"%d",&valueBlue);
       fscanf(fGreen,"%d",&valueGreen);
       fscanf(fRed,"%d",&valueRed);
    }
}
void removeAllcolour(int choice){
   if(choice==1){//CHOICE 1 FOR RED
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(red[i][j]>=blue[i][j]&&red[i][j]>=green[i][j])
             red[i][j]=0;
        }
      }
   }
   if(choice==2){//CHOICE 2 FOR BLUE
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(blue[i][j]>=red[i][j]&&blue[i][j]>=green[i][j])
             blue[i][j]=0;
        }
      }
   }
   if(choice==3){//CHOICE 3 FOR GREEN
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(green[i][j]>=blue[i][j]&&green[i][j]>=red[i][j])
             green[i][j]=0;
        }
      }
   }
}
void preseveOneColour(int choice){
   if(choice==1){//CHOICE 1 FOR RED
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(!(red[i][j]>=blue[i][j]&&red[i][j]>=green[i][j])){
               blue[i][j]=0;
               green[i][j]=0;
           }
        }
      }
   }
   if(choice==2){//CHOICE 2 FOR BLUE
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(!(blue[i][j]>=red[i][j]&&blue[i][j]>=green[i][j])){
              red[i][j]=0;
              green[i][j]=0;
           }
        }
      }
   }
   if(choice==3){//CHOICE 3 FOR GREEN
      for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
           if(red[i][j]==-1 && blue[i][j]==-1 && green[i][j]==-1)
             break;
           if(!(green[i][j]>=blue[i][j]&&green[i][j]>=red[i][j])){
              blue[i][j]=0;
              red[i][j]=0;
           }
        }
      }
   }
}
int main(){
    assignvalueinit();
    assignvalue();
    printf("1:Remove One Color:\n");
    printf("2:Preserve One Color:\n");
    printf("3:Print:\n");
    printf("-1:Exit:\n");
    int choice;
    scanf("%d",&choice);
    while(choice!=-1){
       if(choice==1||choice==2){
          printf("\t1:Red\n\t2:Blue\n\t3:Green");
          int choice2;
          printf("\t");
          scanf("%d",&choice2);
          if(choice==1){
             removeAllcolour(choice2);
          }
          else if(choice==2){
              preseveOneColour(choice2);
          }
       }
       else if(choice==3){
          printf("\t\tENTER X AND Y:\n\t\t");
          int x,y;
          scanf("%d",&x);
          scanf("%d",&y);
          printf("RED:%d\n",red[x][y]);
          printf("BLUE:%d\n",blue[x][y]);
          printf("GREEN:%d\n",green[x][y]);
       }
       else
         printf("INVALID!\n");
       printf("1:Remove One Color:\n");
       printf("2:Preserve One Color:\n");
       printf("3:Print:\n");
       printf("-1:Exit:\n");
       scanf("%d",&choice);
    }
}
