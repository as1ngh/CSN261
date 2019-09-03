#include<stdio.h>
//!Compares input and decrypted file character by character
int main(){
   FILE * input=fopen("inputfile.txt","r");
   FILE * decrypted=fopen("decryptedOutputfile.txt","r");
   char a,b;
   while(!feof(input)&&!feof(decrypted)){
      fscanf(input,"%c",&a);
      fscanf(decrypted,"%c",&b);
      if(!feof(input)&&!feof(decrypted))
      printf("%c %c\n",a,b);
      if(a!=b){
        printf("DEFECTED %c %c",a,b);
        return 0;
      }
   }
   printf("OK!");
}
