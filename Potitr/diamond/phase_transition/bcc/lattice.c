#include<stdio.h>
#include<stdlib.h>

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
double lat[10];
double latlow=a-0.1*a;

FILE* balchal;
balchal=fopen("out","w+");

int i;
for(i=0;i<10;i++){

lat[i]=latlow+i*a*0.025;
fprintf(balchal,"%lf\n",lat[i]);

}

return 0;

}


