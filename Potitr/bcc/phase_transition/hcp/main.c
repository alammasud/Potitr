#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"myheader.h"
#include"create_hcp1.h"


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

int nx,ny,nz,ntot;
a=3.80;
nx=1;ny=1;nz=1;
ntot=4*nx*ny*nz;
double* x; double* y;double* z;

double* lx;double* ly;double* lz; 


x=(double*) malloc(ntot*sizeof(double));
y=(double*) malloc(ntot*sizeof(double));
z=(double*) malloc(ntot*sizeof(double));

lx=(double*) malloc(3*sizeof(double));
ly=(double*) malloc(3*sizeof(double));
lz=(double*) malloc(3*sizeof(double));



create_hcp1(nx,ny,nz,ntot, a,x,y,z,lx,ly,lz);
// basal_hcp(nx,ny,nz,ntot,a,x,y,z,lx,ly,lz);



generate_datafile_for_lammps(lx,ly,lz,a,x,y,z,ntot);


input_file();



return 0;
}
