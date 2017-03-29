#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){

double a;

FILE* lattice;
lattice=fopen("latticefile.txt","r");
        if(lattice==NULL)
        {
                printf("No datas can be found in the File");
                exit(1);
        }

        while(fscanf(lattice,"%le ", &a) != feof(lattice))
        {
           printf("latticeparameter=%le\n",a);
         break;
        }

        fclose(lattice);
double lat[41];
double latlow=a*sqrt(3.0)/2.0/40.0;

FILE* balchal;
balchal=fopen("out","w+");

int i;
for(i=0;i<41;i++){

lat[i]=i*latlow;
fprintf(balchal,"%lf\n",lat[i]);

}
fclose(balchal);
return 0;

}


