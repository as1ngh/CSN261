#include<stdio.h>
FILE * inputfile;
FILE * outputfile;
void encrypt(int n,int a,int b){
   inputfile=fopen("inputfile.txt","r");
   outputfile=fopen("outputfile.txt","w");
   char *line=(char*)malloc(n*sizeof(char));
   int k=0;
   while(!feof(inputfile)){
     char ch='\0';
     char * line=malloc(n*sizeof(char));
        for(int i=0;i<n;i++){
            ch='-';
            if(!feof(inputfile))
               fscanf(inputfile,"%c",&ch);
            else{
               ch='-';
            }
            line[i]=ch;
        }
     char *oline=malloc(n*sizeof(char));
     for(int i=0;i<n;i++){
        int j=(a*i+b)%n;
        oline[i]=line[j];
     }
     printf("%s\n",oline);
     fprintf(outputfile,"%s",oline);
   }
}
int main(){
    int n=5,a=3,b=2;
    encrypt(n,a,b);
}
