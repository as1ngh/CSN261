#include<stdio.h>
#include<stdlib.h>
FILE * inputfile;
FILE * outputfile;
//!Divides the input file in sections of n and decrypt them individualy and print them in decrypted output file
void decrypt(int n,int a,int b){

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
int main(int argc, const char *argv[]){
    if(argc<5){
        printf("ERROR: LESS INPUT\n");
        return 0;
    }
    int n,a,b;
    n=atoi(argv[1]);
    if(n<1){
        printf("ERROR: INVALID N\n");
        return 0;
    }
    a=atoi(argv[2]);
    b=atoi(argv[3]);
    inputfile=fopen(argv[4],"r");
    decrypt(n,a,b);
}
