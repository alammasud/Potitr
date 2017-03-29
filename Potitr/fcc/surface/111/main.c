#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"myheader.h"
#include"deformation.h"


int main(){
double a,duplicate;

FILE* lattice;
lattice=fopen("latticefile.txt","r");
	if(lattice==NULL)
 	{
     		printf("No datas can be found in the File");
     		exit(1);
 	}

 	while(fscanf(lattice,"%le %le ", &a,&duplicate) != feof(lattice))
 	{
 	   printf("latticeparameter=%le\n",a);
 	 break;
 	}
	
	fclose(lattice);

int nx,ny,nz,ntot;

nx=2;ny=2;nz=duplicate;
ntot=6*nx*ny*nz;
double* x; double* y;double* z;

double* lx;double* ly;double* lz; 


x=(double*) malloc(ntot*sizeof(double));
y=(double*) malloc(ntot*sizeof(double));
z=(double*) malloc(ntot*sizeof(double));

lx=(double*) malloc(3*sizeof(double));
ly=(double*) malloc(3*sizeof(double));
lz=(double*) malloc(3*sizeof(double));

double* strain;
strain=(double*) malloc(6*sizeof(double));


//create_fcc_111(nx,ny,nz,ntot, a,x,y,z,lx,ly,lz);
 deformation(x, y,z,lx,ly,lz,strain,ntot,a,nx,ny,nz);
generate_datafile_for_lammps(lx,ly,lz,a,x,y,z,ntot);


input_file();



return 0;
}