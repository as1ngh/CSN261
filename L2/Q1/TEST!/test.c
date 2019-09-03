#include <stdio.h>
#define LEN 256
int main ()
{
   FILE * fp;
   fp = fopen ("inputfile.txt","w");
   fprintf (fp, "Hello, World!");
   fclose (fp);
   return 0;
}
