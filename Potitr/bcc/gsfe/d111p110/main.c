#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"myheader.h"
#include"create_bcc_111.h"


int main(){
double a;

//a=3.510;


FILE* lattice;
lattice=fopen("latticefile.txt","r");
	if(lattice==NULL)
 	{
     		printf("No datas can be found in the File");
     		exit(1);
 	}

 	while(fscanf(lattice,"%lf ", &a) != feof(lattice))
 	{
 	   printf("latticeparameter=%lf\n",a);
 	 break;
 	}
	
	fclose(lattice);


int nx,ny,nz,ntot;

nx=2;ny=8;nz=2;
ntot=6*nx*ny*nz;
double* x; double* y;double* z;

double* lx;double* ly;double* lz; 


x=(double*) malloc(ntot*sizeof(double));
y=(double*) malloc(ntot*sizeof(double));
z=(double*) malloc(ntot*sizeof(double));

lx=(double*) malloc(3*sizeof(double));
ly=(double*) malloc(3*sizeof(double));
lz=(double*) malloc(3*sizeof(double));

create_bcc_111(nx,ny,nz,ntot,a,x,y,z,lx,ly,lz);

generate_datafile_for_lammps(lx,ly,lz,a,x,y,z,ntot);

 input_file(lx,ly,lz);



return 0;
}