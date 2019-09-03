#include<stdio.h>
FILE * inputfile;
FILE * outputfile;
//!Divides the input file in sections of n and encrypt them individualy and print them in output file
void encrypt(int n,int a,int b){
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
    encrypt(n,a,b);
}
