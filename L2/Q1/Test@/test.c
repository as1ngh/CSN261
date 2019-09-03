#include <stdio.h>
#define LEN 256
int main ()
{
   FILE * fp;
   fp = fopen ("inputfile.txt","w");
   fprintf (fp, "hello@12\n3");
   fclose (fp);
   return 0;
}
