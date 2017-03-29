#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define pt 101

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
double lat[pt];
double pt1=pt-1;
double latlow=a*sqrt(6.0)/2.0/pt1;

FILE* balchal;
balchal=fopen("out","w+");

int i;
for(i=0;i<pt;i++){

lat[i]=i*latlow;
fprintf(balchal,"%lf\n",lat[i]);

}

return 0;

}


