#include<stdio.h>
FILE * inputfile;
FILE * outputfile;
//!Divides the input file in sections of n and decrypt them individualy and print them in decrypted output file
void decrypt(int n,int a,int b){
   inputfile=fopen("outputfile.txt","r");
   outputfile=fopen("decryptedOutputfile.txt","w");
   char *line=(char*)malloc(n*sizeof(char));
   int k=0;
   while(!feof(inputfile)){
     char ch;
     char * line=malloc(n*sizeof(char));
        for(int i=0;i<n;i++){
            if(!feof(inputfile))
               fscanf(inputfile,"%c",&ch);
            else{
                break;
            }
            line[i]=ch;
        }
     char *oline=malloc(n*sizeof(char));
     for(int i=0;i<n;i++){
        int j=(a*i+b)%n;
        if(line[i]!='-')
        oline[j]=line[i];
        else
        oline[j]='\0';
     }
     printf("%s\n",oline);
     fprintf(outputfile,"%s",oline);
   }
}
int main(){
    int n=5,a=3,b=2;
    printf("ENTER n:");
    scanf("%d",&n);
    printf("ENTER a:");
    scanf("%d",&a);
    printf("ENTER b:");
    scanf("%d",&b);
    decrypt(n,a,b);
}
